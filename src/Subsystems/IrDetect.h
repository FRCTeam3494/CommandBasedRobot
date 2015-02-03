#ifndef IrDetect_H
#define IrDetect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IrDetect: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	IrDetect();
	void InitDefaultCommand();

	DigitalInput* Optical0;
	// True = on; False = off;
	bool OpticalState;
};

#endif
