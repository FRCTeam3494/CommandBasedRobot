#ifndef Solenoid_Shifter_Set_H
#define Solenoid_Shifter_Set_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Solenoid_Shifter_Set: public CommandBase
{
public:
	Solenoid_Shifter_Set();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
