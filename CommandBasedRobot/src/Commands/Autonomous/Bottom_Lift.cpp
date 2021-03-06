#include "Bottom_Lift.h"

Bottom_Lift::Bottom_Lift()
{
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Bottom_Lift::Initialize() {

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Bottom_Lift::Execute() {
	CommandBase::lift->move(-1);
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Bottom_Lift::IsFinished() {
	return CommandBase::lift->limit;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Bottom_Lift::End() {

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Bottom_Lift::Interrupted() {

}

///////////////////////////////////////////////////////////////////////////////////////
