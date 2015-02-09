#include "IrCheck.h"
#include "../SubSystems/IrDetect.h"

IrCheck::IrCheck()
{
	Infinite = 1;
	while(Infinite == 1)
	{
		if(IrDetect::OpticalState == TRUE)
		{
			SmartDashboard::PutString("off", "");
		}
		else {
			SmartDashboard::PutString("on", "");
		}
	}
}

// Called just before this Command runs the first time
void IrCheck::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IrCheck::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IrCheck::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IrCheck::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IrCheck::Interrupted()
{

}
