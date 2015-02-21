#include "Shift_Down.h"
#include "Subsystems/DriveTrain.h"

Shift_Down::Shift_Down()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Shift_Down::Initialize()
{
	SmartDashboard::init();
}

// Called repeatedly when this Command is scheduled to run
void Shift_Down::Execute()
{
	CommandBase::driveTrain->ChangeGear(true);
}

// Make this return true when this Command no longer needs to run execute()
bool Shift_Down::IsFinished()
{
	SmartDashboard::PutString("Roller_State","DONE");
	return true;
}

// Called once after isFinished returns true
void Shift_Down::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shift_Down::Interrupted()
{

}
