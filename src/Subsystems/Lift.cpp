#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lifting.h"
#include "Commands/Print.h"
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

	Clip = new Solenoid(CLIPSOL);

	SmartDashboard::init();
	//leftIR=new AnalogInput(LEFT_IR);
	//rightIR=new AnalogInput(RIGHT_IR);

	rightVoltage = 0;

	leftVoltage = 0 ;

	leftMeters = 0.0;
	rightMeters = 0.0;

	//LightSensorUp = new AnalogInput(SENSOR_UP);
	//LightSensorDown = new AnalogInput(SENSOR_DOWN);

	//limitSwitchDown = new DigitalInput(LIMITSWITCHDOWN);


}


void Lift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Lifting());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lift::move(float magnitude) {

	//SmartDashboard::PutBoolean("Digital_Encoder", ReachLimit());
	//unsure which is positive, which is negative
	//if(talonRight->GetAnalogInRaw() || talonLeft->GetBusVoltage() > 0)
	//{

	//if fast
	if (mode){
		magnitude = magnitude * 0.95;
	} else {
		magnitude = magnitude/1.5;
	}

	talonRight->Set(-magnitude);
	talonLeft->Set(magnitude);
	//SmartDashboard::PutBoolean("Limit_Switch_Down",limitSwitchDown ->Get());
}

void Lift::ChangeMode(bool fast){
	mode = fast;
}

void Lift::MovePusher(float speed)
{
	pusherRight->Set(-speed);
	pusherLeft->Set(-speed);

}

void Lift::L_Sol_Set() {

	Clip->Set(true);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lift::L_Sol_Off() {
	Clip->Set(false);
}
