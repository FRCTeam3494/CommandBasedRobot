#include "Solenoids.h"
#include "../RobotMap.h"
#include "Commands/Solenoid_Pusher_Set.h"

Solenoids::Solenoids() :
		Subsystem("Solenoids")
{

	solenoid_Roller = new DoubleSolenoid(SOL_ROLLER_1,SOL_ROLLER_2);
	solenoid_Shifter = new DoubleSolenoid(SOL_SHIFT_1,SOL_SHIFT_2);
	solenoid_Pusher = new Solenoid(SOL_PUSH);
}

void Solenoids::InitDefaultCommand()
{




	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void Solenoids::Pusher_on(bool pusher_set)
{
	if (pusher_set == true)
	{
	solenoid_Pusher->Set(TRUE);
	}
	else
	{

	}
}
void Solenoids::Pusher_off(bool pusher_set)
{

	if (pusher_set == false)
	{
	solenoid_Pusher->Set(FALSE);
	}

	else{}

}
void Solenoids::Roller_on()
{}

void Solenoids::Roller_off()
{

	}
void Solenoids::Shifter_High_Gear()
{
	solenoid_Pusher->Set(DoubleSolenoid::Value::kForward);
	}
void Solenoids::Shifter_Low_Gear()
{
	solenoid_Pusher->Set(DoubleSolenoid::Value::kReverse);


}

