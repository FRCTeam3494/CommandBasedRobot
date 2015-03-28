#ifndef Autonimous_Roller_H
#define Autonimous_Roller_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Autonimous_Roller: public CommandBase
{
public:
	Autonimous_Roller(bool _on);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool on;
};

#endif
