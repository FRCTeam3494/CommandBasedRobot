
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/Compressor_Closed_Loop.h"
#include "Commands/Autonomous/Autonomous_Sequence.h"
#include "Commands/Rollers/Set_Roller.h"
class Robot: public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	Command * autonomousSequence;

	void RobotInit() {
		CommandBase::init();
//		autonomousCommand = new ExampleCommand();
		SmartDashboard::init();
		lw = LiveWindow::GetInstance();
		autonomousSequence = new Autonomous_Sequence();

	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() {
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
		if (autonomousSequence != NULL)
			autonomousSequence->Start();
	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

		if (autonomousSequence != NULL)
			autonomousSequence->Cancel();

	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();

	}

	void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

/*

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
 drivetrain->TankDrive(1,-1);
 }

 void Robot::TestPeriodic() {

 lw->Run();
 }

 START_ROBOT_CLASS(Robot);
 */
