#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Lift: public Subsystem {
private:
	CANTalon* talonLeft;
	CANTalon* talonRight;


	AnalogInput* limitSwitchDown;
	double limit;

	double rightVoltage;

	double leftVoltage;

	double leftMeters;
	double rightMeters;
	bool mode;

	Solenoid* Clip;

public:
	Lift();
	void InitDefaultCommand();

	void MovePusher(float speed);

	void ChangeMode(bool fast);
	//positive: move up
	//negative: move down
	void move(float magnitude);
	void L_Sol_Set();
	void L_Sol_Off();
};

#endif

