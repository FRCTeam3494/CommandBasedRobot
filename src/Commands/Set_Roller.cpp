#include "Set_Roller.h"

Set_Roller::Set_Roller(float _on_roller)
{

	Requires(CommandBase::roller);


on_roller = _on_roller;


}

// Called just before this Command runs the first time
void Set_Roller::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Set_Roller::Execute()
{
	CommandBase::roller->Roll(on_roller);

}

// Make this return true when this Command no longer needs to run execute()
bool Set_Roller::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Set_Roller::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Set_Roller::Interrupted()
{

}
