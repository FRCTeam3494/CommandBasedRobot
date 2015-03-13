#include "Autonimous_Roller.h"

Autonimous_Roller::Autonimous_Roller(float _time)
{
	letime = _time;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Autonimous_Roller::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Autonimous_Roller::Execute()
{
	oi->SetAuto(true);
	Wait(letime);
	oi->SetAuto(false);
}

// Make this return true when this Command no longer needs to run execute()
bool Autonimous_Roller::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Autonimous_Roller::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonimous_Roller::Interrupted()
{

}
