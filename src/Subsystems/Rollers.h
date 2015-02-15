#ifndef Rollers_H
#define Rollers_H

#include "../RobotMap.h"

#include "Commands/Subsystem.h"
#include "WPILib.h"


class Rollers: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* talonleft;
	Talon* talonright;
public:
	Rollers();
	void InitDefaultCommand();
	void Roll(float on_roller);
};

#endif
