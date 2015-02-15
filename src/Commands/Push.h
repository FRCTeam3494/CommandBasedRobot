#ifndef Push_H
#define Push_H

#include "../CommandBase.h"
#include "WPILib.h"

class Push: public CommandBase
{
public:
	Push();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
