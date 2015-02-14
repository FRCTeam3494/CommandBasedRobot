#ifndef checkPressure_H
#define checkPressure_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Kompressor.h"

class checkPressure: public CommandBase
{
public:
	checkPressure();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	//pressure in psi
	float pressure;
};

#endif
