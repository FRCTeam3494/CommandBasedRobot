#include "Cut_Power.h"
#include "Subsystems/DriveTrain.h"

Cut_Power::Cut_Power()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);


}

// Called just before this Command runs the first time
void Cut_Power::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Cut_Power::Execute()
{
	CommandBase::driveTrain->HalfPower();
}

// Make this return true when this Command no longer needs to run execute()
bool Cut_Power::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Cut_Power::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Cut_Power::Interrupted()
{

}