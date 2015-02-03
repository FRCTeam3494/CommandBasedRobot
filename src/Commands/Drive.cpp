#include "Drive.h"
#include "../Subsystems/DriveTrain.h"
#include "Robot.h"

Drive::Drive() {
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	//drivetrain->TankDrive(1, -1);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
