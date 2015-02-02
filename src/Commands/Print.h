#ifndef Print_H
#define Print_H

#include "../CommandBase.h"
#include "WPILib.h"

class Print: public CommandBase
{
public:
	Print();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
