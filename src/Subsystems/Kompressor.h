#ifndef Kompressor_H
#define Kompressor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Kompressor: public Subsystem
{
private:
	Compressor* compressor;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Kompressor();
	void Kompressor_Stop();
	void Kompressor_Start();
	void InitDefaultCommand();
	void Kompressor_Closed_Loop(bool on);
	bool PressureSwitchState();

};

#endif
