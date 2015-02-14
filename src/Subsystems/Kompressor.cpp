#include "Kompressor.h"
#include "../RobotMap.h"

Kompressor::Kompressor() :
		Subsystem("ExampleSubsystem")
{

		 compressorSpike_1 = new Relay(1);
		 PressureSensor = new AnalogInput(1);
		 floatPressure = 0.0;
		 voltPressure = 0.0;

}

void Kompressor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

float Kompressor::getPressure() {
		floatPressure = PressureSensor->GetValue();
		voltPressure = PressureSensor->GetVoltage();
		 float pressure = (0.1706 * floatPressure - 14.984 + 33.058 * voltPressure- 15.406) / 2;
		if (pressure < 1.0f) {
			pressure = 0;
		}

		return pressure;
	}

void Kompressor::CompressorToggle(bool isOn)
{
	if(isOn)
	{
		compressorSpike_1->Set(compressorSpike_1->kForward);
	}
	else
	{

		compressorSpike_1->Set(compressorSpike_1->kOff);
	}
}

/*void Kompressor::chargeCompressor(float maxAmount)
{


	}*/

// Put methods for controlling this subsystem
// here. Call these from Commands.
