#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"
#include "../Commands/DriveBase_Command_Group.h"

//0.478779 meters per revolution
//20166 encoder units per meter
//9451 encoder units per revolution

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain") {
	talonLeftMaster = new CANTalon(LEFT_MOTOR_MASTER);
	talonLeftFollowerA = new CANTalon(LEFT_MOTOR_FOLLOWER_A);
	talonLeftFollowerB = new CANTalon(LEFT_MOTOR_FOLLOWER_B);
	talonRightMaster = new CANTalon(RIGHT_MOTOR_MASTER);
	talonRightFollowerA = new CANTalon(RIGHT_MOTOR_FOLLOWER_A);
	talonRightFollowerB = new CANTalon(RIGHT_MOTOR_FOLLOWER_B);

	// Talon 2 follow 1
	talonRightFollowerA->SetControlMode(CANSpeedController::kFollower);
	talonRightFollowerA->Set(RIGHT_MOTOR_MASTER);

	talonRightFollowerB->SetControlMode(CANSpeedController::kFollower);
	talonRightFollowerB->Set(RIGHT_MOTOR_MASTER);

	//Talon 4 follow 3
	talonLeftFollowerA->SetControlMode(CANSpeedController::kFollower);
	talonLeftFollowerA->Set(LEFT_MOTOR_MASTER);

	talonLeftFollowerB->SetControlMode(CANSpeedController::kFollower);
	talonLeftFollowerB->Set(LEFT_MOTOR_MASTER);

	talonLeftMaster->EnableControl();
	talonRightMaster->EnableControl();

	talonLeftMaster->SetSafetyEnabled(false);
	talonLeftMaster->SetExpiration(0.100);
	talonLeftMaster->Set(0);

	talonRightMaster->SetSafetyEnabled(false);
	talonRightMaster->SetExpiration(0.100);
	talonRightMaster->Set(0);

	gyro = new Gyro(0);

	solenoid_Shifter = new DoubleSolenoid(6, 7);

	//false equals low gear
	currentGear = false;
<<<<<<< HEAD
	encoder_1 = talonLeftMaster->GetEncVel();


=======

	position = 0.0;
	velocityLeft = 0.0;
	velocityRight = 0.0;
>>>>>>> origin/master

}

float DriveTrain::GetAngle() {
	return gyro->GetAngle();
}

void DriveTrain::ResetGyro() {
	gyro->Reset();
}

float DriveTrain::GetPosition() {
	return ((talonRightMaster->GetEncPosition()-talonLeftMaster->GetEncPosition())/2);
}

void DriveTrain::ResetEncoders() {
	talonRightMaster->SetPosition(0);
	talonLeftMaster->SetPosition(0);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::TankDrive(float leftAxis, float rightAxis) {

	/*
	 //Deadband for left!!!!!!
	 if (abs(leftAxis) >= 0.09f) {
	 talonRightMaster->Set(leftAxis);
	 } else {
	 talonRightMaster->Set(0.0f);
	 }

	 //deadband for Right!!!!!!!!!!!!!!!!!!!
	 if (abs(rightAxis) >= 0.09f) {
	 talonLeftMaster->Set(rightAxis);
	 } else {
	 talonLeftMaster->Set(0.0f);
	 }

	 */

	velocityRight = talonRightMaster->GetEncVel();
	velocityLeft = talonLeftMaster->GetEncVel();

	SmartDashboard::PutNumber("encoder Left Velocity", velocityLeft);
	SmartDashboard::PutNumber("encoder_Right_Velocity", velocityRight);
	SmartDashboard::PutNumber("Position", GetPosition());

	talonRightMaster->Set(rightAxis);
	talonLeftMaster->Set(leftAxis);
	SmartDashboard::PutNumber("encoder_1", encoder_1);

}

void DriveTrain::ChangeGear(bool _gear) {
	if (currentGear == _gear) {

	} else {
		if (_gear) {
			//solenoid_Shifter_Right->Set(solenoid_Shifter_Right->kForward);
			solenoid_Shifter->Set(solenoid_Shifter->kForward);

		} else if (!_gear) {

			//solenoid_Shifter_Right->Set(solenoid_Shifter_Right->kReverse);
			solenoid_Shifter->Set(solenoid_Shifter->kReverse);

		}
		currentGear = _gear;
	}

}

