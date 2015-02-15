#include "Solenoid_Roller_Set.h"

Solenoid_Roller_Set::Solenoid_Roller_Set()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::solenoids);
}

// Called just before this Command runs the first time
void Solenoid_Roller_Set::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Solenoid_Roller_Set::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Solenoid_Roller_Set::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Solenoid_Roller_Set::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Solenoid_Roller_Set::Interrupted()
{

}
