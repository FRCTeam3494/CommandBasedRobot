#ifndef LiftSystem_H
#define LiftSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftSystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LiftSystem();
	void InitDefaultCommand();
};

#endif
