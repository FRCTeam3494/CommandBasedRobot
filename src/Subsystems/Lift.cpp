#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lifting.h"

Lift::Lift() : Subsystem("Lift")
{
	talonLeft = new CANTalon(LEFT_LIFT);
	talonRight = new CANTalon(RIGHT_LIFT);

	talonLeft->EnableControl();
	talonRight->EnableControl();

	talonLeft->SetSafetyEnabled(true);
	talonLeft->SetExpiration(0.100);
	talonLeft->Set(0);

	talonRight->SetSafetyEnabled(true);
	talonRight->SetExpiration(0.100);
	talonRight->Set(0);
}


void Lift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Lifting());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lift::move(float magnitude) {

	//unsure which is positive, which is negative
	talonRight->Set(-magnitude);
	talonLeft->Set(magnitude);


}


