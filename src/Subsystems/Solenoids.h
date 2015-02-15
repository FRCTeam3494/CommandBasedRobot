#ifndef Solenoids_H
#define Solenoids_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Solenoids: public Subsystem
{
private:
	DoubleSolenoid* solenoid_Roller;
	Solenoid* solenoid_Pusher;
	DoubleSolenoid* solenoid_Shifter; //Low gear 2 High gear 3
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Solenoids();
	void InitDefaultCommand();
	void Pusher_on(bool pusher_set);
	void Pusher_off(bool pusher_set);
	void Roller_on();
	void Roller_off();
	void Shifter_High_Gear();
	void Shifter_Low_Gear();

};

#endif
