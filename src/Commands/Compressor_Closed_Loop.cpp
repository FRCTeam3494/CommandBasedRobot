#include "Compressor_Closed_Loop.h"
#include "Subsystems/Kompressor.h"

Compressor_Closed_Loop::Compressor_Closed_Loop()
{

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Compressor_Closed_Loop::Initialize()
{


}

// Called repeatedly when this Command is scheduled to run
void Compressor_Closed_Loop::Execute()
{
//CommandBase::kompressor->Kompressor_Toggle();
}

// Make this return true when this Command no longer needs to run execute()
bool Compressor_Closed_Loop::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Compressor_Closed_Loop::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Compressor_Closed_Loop::Interrupted()
{

}
