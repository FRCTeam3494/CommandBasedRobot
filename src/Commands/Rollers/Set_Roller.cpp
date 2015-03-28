#include "Set_Roller.h"
#include "../../Robot.h"

Set_Roller::Set_Roller()
{

	Requires(CommandBase::roller);
}

// Called just before this Command runs the first time
void Set_Roller::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Set_Roller::Execute()
{
	if (oi->GetLeftBumper()){
		CommandBase::roller->Roll(-0.5);
	} else if (oi->GetRightBumper()){
		CommandBase::roller->Roll(0.5);
	} else if (oi->Auto()){
		CommandBase::roller->Roll(0.5);
	} else {
		CommandBase::roller->Roll(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Set_Roller::IsFinished()
{
	return false;
}


// Called once after isFinished returns true
void Set_Roller::End()
{
	//CommandBase::roller->Roll(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Set_Roller::Interrupted()
{

}
