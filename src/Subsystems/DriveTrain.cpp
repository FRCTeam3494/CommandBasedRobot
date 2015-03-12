#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive/Drive.h"
#include "../Commands/Drive/DriveBase_Command_Group.h"
#include <math.h>


//0.478779 meters per revolution
//20166 encoder units per meter
//9451 encoder units per revolution

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain") {
	talonLeftMaster = new CANTalon(LEFT_MOTOR_MASTER);
	talon_strafe = new CANTalon(Strafe_);
	talonLeftFollowerA = new CANTalon(LEFT_MOTOR_FOLLOWER_A);
	talonRightMaster = new CANTalon(RIGHT_MOTOR_MASTER);
	talonRightFollowerA = new CANTalon(RIGHT_MOTOR_FOLLOWER_A);
	//talonRightFollowerB = new CANTalon(RIGHT_MOTOR_FOLLOWER_B);

	/*// Talon 2 follow 1
	talonRightFollowerA->SetControlMode(CANSpeedController::kFollower);
	talonRightFollowerA->Set(RIGHT_MOTOR_MASTER);

	talonRightFollowerB->SetControlMode(CANSpeedController::kFollower);
	talonRightFollowerB->Set(RIGHT_MOTOR_MASTER);

	//Talon 4 follow 3
	talonLeftFollowerA->SetControlMode(CANSpeedController::kFollower);
	talonLeftFollowerA->Set(LEFT_MOTOR_MASTER);

	talonLeftFollowerB->SetControlMode(CANSpeedController::kFollower);
	talonLeftFollowerB->Set(LEFT_MOTOR_MASTER);
	*/

	talonLeftMaster->EnableControl();
	talonRightMaster->EnableControl();

	talonRightFollowerA->EnableControl();
	//talonRightFollowerB->EnableControl();

	talonLeftFollowerA->EnableControl();
	talon_strafe->EnableControl();

	talonLeftMaster->SetSafetyEnabled(false);
	talonLeftFollowerA->SetSafetyEnabled(false);
	talon_strafe->SetSafetyEnabled(false);
	talonLeftMaster->SetExpiration(0.100);
	talonLeftMaster->Set(0);

	talonRightMaster->SetSafetyEnabled(false);
	talonRightFollowerA->SetSafetyEnabled(false);
	//talonRightFollowerB->SetSafetyEnabled(false);
	talonRightMaster->SetExpiration(0.100);
	talonRightMaster->Set(0);

	//gyro = new Gyro(1);
//////////////////////////////////////////////////////////////////////////
	table = NetworkTable::GetTable("datatable");
	                serial_port = new SerialPort(57600,SerialPort::kMXP);
	        uint8_t update_rate_hz = 50;
	#if defined(ENABLE_AHRS)
	        imu = new AHRS(serial_port,update_rate_hz);
	#elif defined(ENABLE_IMU_ADVANCED)
	        imu = new IMUAdvanced(serial_port,update_rate_hz);
	#else // ENABLE_IMU
	        imu = new IMU(serial_port,update_rate_hz);
	#endif

////////////////////////////////////////////////////////////////////////
	solenoid_Shifter = new DoubleSolenoid(SOL_SHIFT_1, SOL_SHIFT_2);

	//false equals low gear
	currentGear = false;

	position = 0.0;
	velocityLeft = 0.0;
	velocityRight = 0.0;

	cutPower = false;

}

float DriveTrain::GetAngle() {
	return gyro->GetAngle();
}

void DriveTrain::ResetGyro() {
	gyro->Reset();
}

float DriveTrain::GetPosition() {
	return ((talonRightMaster->GetEncPosition()- talonLeftMaster->GetEncPosition())/2);

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
	if(cutPower == true)
	{
		leftAxis /= 2;
		rightAxis /=2;

	}
	velocityRight = talonRightMaster->GetEncVel();
	velocityLeft = talonLeftMaster->GetEncVel();

	SmartDashboard::PutNumber("encoder Left Velocity", velocityLeft);
	SmartDashboard::PutNumber("encoder_Right_Velocity", velocityRight);
	SmartDashboard::PutNumber("Position", GetPosition());

	/*talonRightMaster->Set(rightAxis);
	talonLeftMaster->Set(leftAxis);

	talonRightFollowerA->Set(rightAxis);
	talonRightFollowerB->Set(rightAxis);

	talonLeftFollowerA->Set(leftAxis);
	talonLeftFollowerB->Set(leftAxis);*/
////////////////////////////////////////////////////////
	SmartDashboard::PutBoolean( "IMU_Connected", imu->IsConnected());
	                        SmartDashboard::PutNumber("IMU_Yaw", imu->GetYaw());
	                        SmartDashboard::PutNumber("IMU_Pitch", imu->GetPitch());
	                        SmartDashboard::PutNumber("IMU_Roll", imu->GetRoll());
	                        SmartDashboard::PutNumber("IMU_CompassHeading", imu->GetCompassHeading());
	                        SmartDashboard::PutNumber("IMU_Update_Count", imu->GetUpdateCount());
	                        SmartDashboard::PutNumber("IMU_Byte_Count", imu->GetByteCount());
////////////////////////////////////////////////////////
	 //Deadband for left!!!!!!

	float power = 2;

	int leftSign = 1;
	int rightSign = 1;

	if(leftAxis <0){
		leftSign = -1;
		leftAxis = leftAxis*-1;
	}

	if (rightAxis <0){
		rightSign = -1;
		rightAxis = rightAxis*-1;
	}

	float leftValue = leftSign * pow(leftAxis, power);
	float rightValue = rightSign * pow(rightAxis, power);



		talonLeftMaster->Set(leftValue);
		 talonLeftFollowerA->Set(leftValue);
		// talon_strafe->Set(leftAxis);


		 //deadband for Right!!!!!!!!!!!!!!!!!!!

		 talonRightMaster->Set(rightValue);
			talonRightFollowerA->Set(rightValue);
			//talonRightFollowerB->Set(rightAxis);

		SmartDashboard::PutNumber("LEFT", leftValue);


SmartDashboard::PutNumber("AAAAAA_GYRO ANGLE",gyro->GetAngle());
}

void DriveTrain::ChangeGear(bool _gear) {
	if (currentGear != _gear) {
		if (_gear) {
			//shifts up
			solenoid_Shifter->Set(solenoid_Shifter->kReverse);

		} else if (!_gear) {
			//shifts down
			solenoid_Shifter->Set(solenoid_Shifter->kForward);
		}
		currentGear = _gear;
	}

}

void DriveTrain::_Strafe(float strafe_axis)
{

	talon_strafe->Set(strafe_axis);


}

void DriveTrain::HalfPower()
{
	if(cutPower == false)
	{
		cutPower = true;
	}
	else if(cutPower == true)
	{

		cutPower = false;
	}

}





