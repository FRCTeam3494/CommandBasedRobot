#ifndef Kompressor_H
#define Kompressor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Kompressor: public Subsystem
{
private:
<<<<<<< HEAD
	Compressor* compressor;

=======
>>>>>>> origin/practice_robot
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Kompressor();
<<<<<<< HEAD
	void Kompressor_Stop();
	void Kompressor_Start();
	void InitDefaultCommand();
	void Kompressor_Closed_Loop(bool on);
	bool PressureSwitchState();

=======
	void InitDefaultCommand();
	//void chargeCompressor(float maxAmount);
	float getPressure();
	void CompressorToggle(bool isOn);


private:
	Relay* compressorSpike_1;
	AnalogInput* PressureSensor;
	float floatPressure;
	float voltPressure;
>>>>>>> origin/practice_robot
};

#endif
