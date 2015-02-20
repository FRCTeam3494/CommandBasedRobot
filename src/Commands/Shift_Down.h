#ifndef Shift_Down_H
#define Shift_Down_H

#include "../CommandBase.h"
#include "WPILib.h"

class Shift_Down: public CommandBase
{
public:
	Shift_Down();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
