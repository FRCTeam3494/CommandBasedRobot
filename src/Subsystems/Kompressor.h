#ifndef Kompressor_H
#define Kompressor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Kompressor: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Kompressor();
	void InitDefaultCommand();
	//void chargeCompressor(float maxAmount);
	float getPressure();
	void CompressorToggle(bool isOn);


private:
	Relay* compressorSpike_1;
	AnalogInput* PressureSensor;
	float floatPressure;
	float voltPressure;
};

#endif
