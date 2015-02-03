#include "WPILib.h"
#include "Commands/Command.h"
#include "Commandbase.h"
#include "Commands/ExampleCommand.h"
#include "Subsystems/DriveTrain.h"

#include "CommandBase.h"
#include "Robot.h"

void Robot::RobotInit() {
	CommandBase::init();
	//autonomousCommand = new ExampleCommand();
	lw = LiveWindow::GetInstance();
	drivetrain = new DriveTrain();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL){
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	drivetrain->TankDrive(1,-1);
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

}

void Robot::TestPeriodic() {

	lw->Run();
}

START_ROBOT_CLASS(Robot);

