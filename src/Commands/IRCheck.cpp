#include "IRCheck.h"

IRCheck::IRCheck()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::irsensor);
}

// Called just before this Command runs the first time
void IRCheck::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IRCheck::Execute()
{
while(1)
{
	if (CommandBase::irsensorIrsensor_1 == TRUE)
	{
		SmartDashboard::PutString("sensor_1", "On");

	}
	else
	{
		SmartDashboard::PutString("sensor_2", "Off");
	}

}
}

// Make this return true when this Command no longer needs to run execute()
bool IRCheck::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IRCheck::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IRCheck::Interrupted()
{

}
