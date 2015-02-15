#include "Kompressor_Kompress.h"

Kompressor_Kompress::Kompressor_Kompress()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::kompressor);
}

// Called just before this Command runs the first time
void Kompressor_Kompress::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Kompressor_Kompress::Execute()
{

	CommandBase::kompressor->Kompressor_Start();

}

// Make this return true when this Command no longer needs to run execute()
bool Kompressor_Kompress::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Kompressor_Kompress::End()
{
CommandBase::kompressor->Kompressor_Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Kompressor_Kompress::Interrupted()
{
CommandBase::kompressor->Kompressor_Stop();
}
