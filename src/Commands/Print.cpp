#include "Print.h"
#include "Subsystems/Lift.h"
Print::Print()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Print::Initialize()
{
	SmartDashboard::init();
}

// Called repeatedly when this Command is scheduled to run
void Print::Execute()
{
	//SmartDashboard::PutBoolean("Digital_Encoder", CommandBase::lift->ReachLimit());


}

// Make this return true when this Command no longer needs to run execute()
bool Print::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Print::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Print::Interrupted()
{

}
