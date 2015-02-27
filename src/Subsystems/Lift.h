#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Lift: public Subsystem {
private:
	CANTalon* talonLeft;
	CANTalon* talonRight;
	AnalogInput* leftIR;
	AnalogInput* rightIR;

	AnalogInput* LightSensorUp;
	AnalogInput* LightSensorDown;


	double rightVoltage;

	double leftVoltage;

	double leftMeters;
	double rightMeters;



public:
	Lift();
	void InitDefaultCommand();
	void CheckIRRight();

	void CheckIRLeft();


	//positive: move up
	//negative: move down
	void move(float magnitude);
};

#endif

