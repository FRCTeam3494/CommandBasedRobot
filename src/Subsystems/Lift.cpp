#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lifting.h"
#include <math.h>

Lift::Lift() : Subsystem("Lift")
{
	talonLeft = new CANTalon(LEFT_LIFT);
	talonRight = new CANTalon(RIGHT_LIFT);

	talonLeft->EnableControl();
	talonRight->EnableControl();

	talonLeft->SetSafetyEnabled(false);
	talonLeft->SetExpiration(0.100);
	talonLeft->Set(0);

	talonRight->SetSafetyEnabled(false);
	talonRight->SetExpiration(0.100);
	talonRight->Set(0);

	Clip = new DoubleSolenoid(CLIPSOL, CLIPSOL_2);
	Clip_ = new DoubleSolenoid(SOL_H, SOL_H1);

	limit = false;
	power = 1.0;
	//rightVoltage = 0;
	//leftVoltage = 0 ;

	//leftMeters = 0.0;
	//rightMeters = 0.0;

	limitSwitchDown = new DigitalInput(0);
	mode = false;

}


void Lift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Lifting());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lift::move(float magnitude) {
	SmartDashboard::PutBoolean("Lift Fast Mode", mode);
	limit = limitSwitchDown->Get();

	//if fast
	if (mode){
		magnitude = magnitude * 0.95;
	} else {
		magnitude = magnitude/1.5;
	}

	//bottomed lift
	if (magnitude < 0 && limit){
		magnitude = magnitude * 0.1;
	}
	talonRight->Set(-magnitude);

	if (magnitude > 0){
		talonLeft->Set(magnitude);
	} else {
		talonLeft->Set(magnitude);
	}

	SmartDashboard::PutBoolean("Bottom Limit",limit);
}

void Lift::ChangeMode(bool fast){
	mode = fast;
}

void Lift::L_Sol_Set() {

	Clip->Set(Clip->kReverse);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lift::L_Sol_Off() {
	Clip->Set(Clip->kForward);
}

void Lift::H_Sol_Set() {

	Clip_->Set(Clip_->kForward);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lift::H_Sol_Off() {
	Clip_->Set(Clip_->kReverse);
}


