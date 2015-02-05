#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
	talonLeftMaster = new CANTalon(LEFT_MOTOR_MASTER);
	talonLeftFollower = new CANTalon(LEFT_MOTOR_FOLLOWER);
	talonRightMaster = new CANTalon(RIGHT_MOTOR_MASTER);
	talonRightFollower = new CANTalon(RIGHT_MOTOR_FOLLOWER);
	
	// Talon 2 follow 1
	talonLeftFollower->SetControlMode(CANSpeedController::kFollower);
	talonLeftFollower->Set(LEFT_MOTOR_MASTER);

	//Talon 4 follow 3
	talonRightFollower->SetControlMode(CANSpeedController::kFollower);
	talonRightFollower->Set(RIGHT_MOTOR_MASTER);

	talonLeftMaster->EnableControl();
	talonRightMaster->EnableControl();

	talonLeftMaster->SetSafetyEnabled(true);
	talonLeftMaster->SetExpiration(0.100);
	talonLeftMaster->Set(0);

	talonRightMaster->SetSafetyEnabled(true);
	talonRightMaster->SetExpiration(0.100);
	talonRightMaster->Set(0);
}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::TankDrive(float leftAxis, float rightAxis) {
	/**
	//Deadband for left!!!!!!!!!!!!!!!!!
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
	**/
	talonRightMaster->Set(-rightAxis);
	talonLeftMaster->Set(leftAxis);

}


/*#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() :
	Subsystem("DriveTrain") {
	talon_1 = new CANTalon(1);
	talon_2 = new CANTalon(2);
	talon_3 = new CANTalon(3);
	talon_4 = new CANTalon(4);

	// Talon 2 follow 1
	talon_2->SetControlMode(CANSpeedController::kFollower);
	talon_2->Set(1);

	//Talon 4 follow 3
	talon_4->SetControlMode(CANSpeedController::kFollower);
	talon_4->Set(3);

	talon_1->EnableControl();
	talon_3->EnableControl();

	talon_1->SetSafetyEnabled(true);
	talon_1->SetExpiration(0.100);
	talon_1->Set(0);

	talon_3->SetSafetyEnabled(true);
	talon_3->SetExpiration(0.100);
	talon_3->Set(0);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::TankDrive(float leftAxis, float rightAxis) {


	talon_1->Set(rightAxis);

	//Deadband for left!!!!!!!!!!!!!!!!!
	if (abs(leftAxis) >= 0.14) {

		talon_3->Set(leftAxis);
	} else {
		talon_3->Set(0.0f);
	}

	//deadband for Right!!!!!!!!!!!!!!!!!!!
	if (abs(rightAxis) >= 0.14f) {

		talon_1->Set(rightAxis);
	} else {
		talon_1->Set(0.0f);
	}

	SmartDashboard::PutNumber("Y_Axis", leftAxis);
	SmartDashboard::PutNumber("Other_Axis", rightAxis);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
*/
