#ifndef IRCheck_H
#define IRCheck_H

#include <Subsystems/Lift.h>
#include "../CommandBase.h"
#include "WPILib.h"

class IRCheck: public CommandBase
{
public:
	IRCheck();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
