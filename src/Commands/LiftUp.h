#ifndef LiftUp_H
#define LiftUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftUp: public CommandBase
{
public:
	LiftUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
