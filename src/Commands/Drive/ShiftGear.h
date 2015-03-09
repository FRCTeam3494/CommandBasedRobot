#ifndef Shift_H
#define Shift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Shift: public CommandBase
{
public:
	Shift(bool _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool mode;
};

#endif
