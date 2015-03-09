#ifndef Autonimous_Roller_H
#define Autonimous_Roller_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Autonimous_Roller: public CommandBase
{
public:
	Autonimous_Roller(float _time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float letime;
};

#endif
