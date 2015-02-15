#include "Solenoid_Pusher_Set.h"

Solenoid_Pusher_Set::Solenoid_Pusher_Set(bool solenoid_pusher)
{
	// Use Requires() here to declare subsystem dependencies
	pusher_set = solenoid_pusher;
	Requires(CommandBase::solenoids);
}

// Called just before this Command runs the first time
void Solenoid_Pusher_Set::Initialize()
{


}

// Called repeatedly when this Command is scheduled to run
void Solenoid_Pusher_Set::Execute()
{
	CommandBase::solenoids->Pusher_on(pusher_set);
}

// Make this return true when this Command no longer needs to run execute()
bool Solenoid_Pusher_Set::IsFinished()
{

	pusher_set = false;
	CommandBase::solenoids->Pusher_on(pusher_set);
	return false;
}

// Called once after isFinished returns true
void Solenoid_Pusher_Set::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Solenoid_Pusher_Set::Interrupted()
{

}
