#include "Drive.h"



Drive::Drive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis)
	Requires(CommandBase::driveTrain);
}

// Called just before this Command runs the first time
void Drive::Initialize()

{
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	float leftThrottle = -1 * oi->GetLeftJoystick();
	float rightThrottle = oi->GetRightJoystick();

	CommandBase::driveTrain->TankDrive(leftThrottle, rightThrottle); // TODO fix joystick
	SmartDashboard::PutNumber("Left", leftThrottle);
	SmartDashboard::PutNumber("Right", rightThrottle);
	//CommandBase::driveTrain->TankDrive(1, -1);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
