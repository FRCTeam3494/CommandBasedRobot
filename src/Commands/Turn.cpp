#include "Turn.h"


Turn::Turn(float _angle, float _speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis)

	Requires(CommandBase::driveTrain);
	CommandBase::driveTrain->ResetGyro();
	//sets target angle
	angle = _angle;
	speed = _speed;
	slow = false;
}

// Called just before this Command runs the first time
void Turn::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute()
{
	if (slow){
		CommandBase::driveTrain->TankDrive(speed/2, speed/2);
	} else {
		CommandBase::driveTrain->TankDrive(speed, speed);
	}
	 // TODO fix joystick
	SmartDashboard::PutNumber("Delta Theta", angle - CommandBase::driveTrain->GetAngle());
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished()
{
	float diff = abs(angle-CommandBase::driveTrain->GetAngle());
	//1 degree accuracy
	if (diff <= 20 && !slow){
		slow = true;
	} else if (diff <=2){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void Turn::End()
{
	//resets everything
	CommandBase::driveTrain->ResetGyro();
	angle = 0;
	slow = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted()
{

}
