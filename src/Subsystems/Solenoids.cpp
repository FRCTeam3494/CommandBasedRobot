#include "Solenoids.h"
#include "../RobotMap.h"
#include "Commands/Solenoid_Pusher_Set.h"

Solenoids::Solenoids() :
		Subsystem("Solenoids")
{

	solenoid_Roller = new DoubleSolenoid(0,1);
	solenoid_Shifter = new DoubleSolenoid(2,3);
	solenoid_Pusher = new Solenoid(4);
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
void Solenoids::Roller_on(bool roller_set)
if ( roller_set == on)
{	solenoid_Roller->Set(DoubleSolenoid::Value::kForward);
	}

else
{

}

void Solenoids::Roller_off()
{
	solenoid_Roller->Set(DoubleSolenoid::Value::kOff);
	}
void Solenoids::Shifter_High_Gear()
{
	solenoid_Pusher->Set(DoubleSolenoid::Value::kForward);
	}
void Solenoids::Shifter_Low_Gear()
{
	solenoid_Pusher->Set(DoubleSolenoid::Value::kReverse);


}

