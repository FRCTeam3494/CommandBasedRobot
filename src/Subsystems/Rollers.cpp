#include "Subsystems/Rollers.h"
#include "../Commands/Set_Roller.h"

Rollers::Rollers() :
		Subsystem("Rollers") {
	talonleft = new Talon(LEFT_ROLLER);
	talonright = new Talon(RIGHT_ROLLER);

	talonleft->SetSafetyEnabled(false);
	talonleft->SetExpiration(0.100);
	talonleft->Set(0);

	talonright->SetSafetyEnabled(false);
	talonright->SetExpiration(0.100);
	talonright->Set(0);

	solenoid = new DoubleSolenoid(2, 3);
}

void Rollers::InitDefaultCommand() {
	SetDefaultCommand(new Set_Roller());
}

void Rollers::Roll(float on_roller) {
	talonright->Set(-on_roller);
	talonleft->Set(on_roller);
}

//close
void Rollers::TriggerSolenoid() {

	solenoid->Set(solenoid->kForward);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Rollers::SolenoidOff() {
	solenoid->Set(solenoid->kReverse);
}
