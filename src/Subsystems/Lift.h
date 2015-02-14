#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lift: public Subsystem {
private:
	CANTalon* talonLeft;
	CANTalon* talonRight;
public:
	Lift();
	void InitDefaultCommand();

	//positive: move up
	//negative: move down
	void move(float magnitude);
};

#endif

