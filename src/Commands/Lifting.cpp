#include "Lifting.h"



Lifting::Lifting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis)
	//Requires(CommandBase::lift);
}

// Called just before this Command runs the first time
void Lifting::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void Lifting::Execute()
{


	//THINK OF SOLUTION
	//GET INPUT HERE
	float magnitude = (oi->GetLeftTrigger() + oi->GetRightTrigger())/2;
	CommandBase::lift->move(magnitude);

	SmartDashboard::PutNumber("Magnitude", magnitude);
}

// Make this return true when this Command no longer needs to run execute()
bool Lifting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Lifting::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lifting::Interrupted()
{

}
