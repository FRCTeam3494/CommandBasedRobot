#include "checkPressure.h"

checkPressure::checkPressure()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::kompressor);
	pressure = 0.0;
}

// Called just before this Command runs the first time
void checkPressure::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void checkPressure::Execute()
{
	pressure = CommandBase::kompressor->getPressure();

	if(pressure <= 75)
	{
		while(pressure <= 120)
		{
			CommandBase::kompressor->CompressorToggle(true);
			SmartDashboard::PutNumber("pressure",pressure);
		}
	}
	else
	{
		CommandBase::kompressor->CompressorToggle(false);
		SmartDashboard::PutNumber("pressure",pressure);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool checkPressure::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void checkPressure::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void checkPressure::Interrupted()
{

}
