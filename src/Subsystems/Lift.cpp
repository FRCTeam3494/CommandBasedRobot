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

	SmartDashboard::init();
	leftIR=new AnalogInput(LEFT_IR);
	rightIR=new AnalogInput(RIGHT_IR);

	rightVoltage = 0;

	leftVoltage = 0 ;

	leftMeters = 0.0;
	rightMeters = 0.0;

	LightSensorUp = new AnalogInput(SENSOR_UP);
	LightSensorDown = new AnalogInput(SENSOR_DOWN);


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

	talonRight->Set(-magnitude);
	talonLeft->Set(magnitude);

/*float LightSense = LightSensorUp->GetVoltage();
	SmartDashboard::PutNumber("UP_LIMIT", LightSensorUp->GetVoltage());
	SmartDashboard::PutNumber("DOWN_LIMIT", LightSensorDown->GetValue());
SmartDashboard::PutNumber("UP_LIMIT", LightSense);*/



	//}
	//else
	//{

		//SmartDashboard::PutString("THE TALON IS NOT WORKING","need to reset");

	//}

}

/*void Lift::CheckIRRight()
{
		rightVoltage = rightIR->GetVoltage();

		rightMeters = -0.175*pow(1/rightVoltage,2) + 1.0077*(1/rightVoltage)-0.2073;


		SmartDashboard::PutNumber("Right_Voltage", rightVoltage);
		SmartDashboard::PutNumber("Right_Meters", rightMeters);
}

void Lift::CheckIRLeft()
{


	leftVoltage = leftIR->GetVoltage();

	leftMeters = -0.1685*pow(1/leftVoltage,2) + 0.9092*(1/leftVoltage) - 0.1714;

		SmartDashboard::PutNumber("Left_Voltage", leftVoltage);
		SmartDashboard::PutNumber("Left_Meters", leftMeters);

}*/

