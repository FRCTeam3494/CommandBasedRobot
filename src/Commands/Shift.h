#ifndef Shift_H
#define Shift_H

#include "../CommandBase.h"
#include "WPILib.h"

class Shift: public CommandBase
{
public:
	Shift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
