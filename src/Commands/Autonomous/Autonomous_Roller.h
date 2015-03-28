#ifndef Autonomous_Roller_H
#define Autonomous_Roller_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Autonomous_Roller: public CommandBase
{
public:
	Autonomous_Roller(int _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int mode;
};

#endif
