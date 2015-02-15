#ifndef Solenoid_Roller_Set_H
#define Solenoid_Roller_Set_H

#include "../CommandBase.h"
#include "WPILib.h"

class Solenoid_Roller_Set: public CommandBase
{
public:
	Solenoid_Roller_Set();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
