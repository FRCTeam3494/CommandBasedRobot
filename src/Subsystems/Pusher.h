#ifndef Pusher_H
#define Pusher_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pusher: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Pusher();
	void InitDefaultCommand();
	//moves the pusher based on the axis value of controller number2
	void MovePusher(float axisValue);
	void TriggerSolenoid();

private:
	Solenoid* solenoid_1;
	Solenoid* solenoid_2;
	Talon* Talon_9;
	Talon* Talon_10;
};

#endif
