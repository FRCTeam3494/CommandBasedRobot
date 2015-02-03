#include "LiftSystem.h"
#include "../RobotMap.h"

LiftSystem::LiftSystem() :
			Subsystem("LiftSystem")
{
			/*talon_1 = new CANTalon(1);
			talon_2 = new CANTalon(2);

			// Talon 2 follow 1
			talon_2->SetControlMode(CANSpeedController::kFollower);
			talon_2->Set(1);

			leftAxis = 0.0f;
			rightAxis = 0.0f;

			talon_1->EnableControl();

			talon_1->SetSafetyEnabled(true);
			talon_1->SetExpiration(0.100);
			talon_1->Set(0);*/
}

void LiftSystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
