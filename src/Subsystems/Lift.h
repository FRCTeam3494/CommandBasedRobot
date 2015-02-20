#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lift: public Subsystem {
private:
	CANTalon* talonLeft;
	CANTalon* talonRight;
	DigitalInput* leftLimitSwitch;

public:
	Lift();
	void InitDefaultCommand();
	bool ReachLimit();


	//positive: move up
	//negative: move down
	void move(float magnitude);
};

#endif

