#include "Subsystems/Rollers.h"
#include "../Commands/Set_Roller.h"


Rollers::Rollers() : Subsystem("Rollers")
{
	talonleft = new Talon(LEFT_ROLLER);
	talonright = new Talon(RIGHT_ROLLER);



		talonleft->SetSafetyEnabled(true);
		talonleft->SetExpiration(0.100);
		talonleft->Set(0);

		talonright->SetSafetyEnabled(true);
		talonright->SetExpiration(0.100);
		talonright->Set(0);

		 solenoid = new DoubleSolenoid(0,1);
}

void Rollers::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new Set_Roller(.4));
	//SetDefaultCommand(new Set_Roller(0));
}

void Rollers::Roll(float on_roller)
{
	talonright->Set(-on_roller);
	talonleft->Set(on_roller);



}

void Rollers::TriggerSolenoid()
{

solenoid->Set(solenoid->kForward);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Rollers::SolenoidOff()
{
	solenoid->Set(solenoid->kReverse);
}
