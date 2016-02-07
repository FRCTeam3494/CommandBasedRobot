#include "Autonomous_Move.h"
#include "Subsystems/DriveTrain.h"

///////////////////////////////////////////////////////////////////////////////////////
Autonomous_Move::Autonomous_Move(float _distance, float _speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::driveTrain);
	distance = _distance;
	speed = _speed;
	CommandBase::driveTrain->ResetEncoders();
	target = (distance); // Dinstance is in inches
	back = false;
	SmartDashboard::init();
	output = 0;


	//DriveTrain::talonRightMaster->SetPID(5, 0.5, 1);

	//DriveTrain::talonRightMaster->SetSetpoint(target);

	//DriveTrain::talonRightMaster->Enable();



}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time



///////////////////////////////////////////////////////////////////////////////////////

void Autonomous_Move::Initialize() {
	CommandBase::driveTrain->ResetEncoders();
	CommandBase::driveTrain->PID_Enable(target);

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Autonomous_Move::Execute() {
//


output = CommandBase::driveTrain->PID_Update(target);
SmartDashboard::PutNumber("PID_Data", output);


	//std::cout << system << std::endl;

	//SmartDashboard::PutNumber("PID_DAta", CommandBase::driveTrain->PID_Update());

	/*if (output <= 0 )
	{
		CommandBase::driveTrain->TankDrive(output, -output);


	}
	else if (output > 0)
	{

		CommandBase::driveTrain->TankDrive(-output, output);

	}*/
CommandBase::driveTrain->TankDrive(-output, output);





}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
///////////////////////////////////////////////////////////////////////////////////////
bool Autonomous_Move::IsFinished() {


/*
	if (CommandBase::driveTrain->GetPosition() >= target && back == false) {
		CommandBase::driveTrain->TankDrive(0, 0);
		CommandBase::driveTrain->ResetEncoders();
		return true;
	}
	if (CommandBase::driveTrain->GetPosition() <= target && back == true) {
		CommandBase::driveTrain->TankDrive(0, 0);
		CommandBase::driveTrain->ResetEncoders();
		return true;
	}
*/
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
///////////////////////////////////////////////////////////////////////////////////////
void Autonomous_Move::End() {

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same

// subsystems is scheduled to run

void Autonomous_Move::Interrupted() {

}

///////////////////////////////////////////////////////////////////////////////////////
