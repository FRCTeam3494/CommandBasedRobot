#include "Pusher.h"
#include "../RobotMap.h"

Pusher::Pusher() :
		Subsystem("ExampleSubsystem")
{
	Talon_9 = new Talon(PUSHER_RIGHT);
	Talon_10 = new Talon(PUSHER_LEFT);

		//Talon_9->EnableControl();
		//Talon_10->EnableControl();

		Talon_9->SetSafetyEnabled(true);
		Talon_9->SetExpiration(0.100);
		Talon_9->Set(0);

		Talon_10->SetSafetyEnabled(true);
		Talon_10->SetExpiration(0.100);
		Talon_10->Set(0);

	//NEED TO PUT IN CORRECT VALUES FOR THE CHANNELS
	solenoid_1 = new Solenoid(2);
	solenoid_2 = new Solenoid(3) ;
}

void Pusher::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Pusher::MovePusher(float axisValue)
{
	Talon_9->Set(axisValue);
	Talon_10->Set(-axisValue);

}

void Pusher::TriggerSolenoid()
{
	solenoid_1->Set(true);
	solenoid_2->Set(true);
	//wait(0.1f);
	solenoid_1->Set(false);
	solenoid_2->Set(false);

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
