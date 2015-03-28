#include "Autonomous_Move.h"
#include "Subsystems/DriveTrain.h"

Autonomous_Move::Autonomous_Move(float _distance, float _speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::driveTrain);
	distance = _distance;
	speed = _speed;

	target = (distance * 9400);
}

// Called just before this Command runs the first time
void Autonomous_Move::Initialize() {
	CommandBase::driveTrain->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void Autonomous_Move::Execute() {
	CommandBase::driveTrain->TankDrive(-speed, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous_Move::IsFinished() {

	if (CommandBase::driveTrain->GetPosition() >= target) {
		CommandBase::driveTrain->TankDrive(0, 0);
		return true;
	}

	return false;
}

// Called once after isFinished returns true
void Autonomous_Move::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous_Move::Interrupted() {

}
