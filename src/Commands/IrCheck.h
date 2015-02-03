#ifndef IrCheck_H
#define IrCheck_H

#include "../SubSystems/IrDetect.h"
#include "../CommandBase.h"
#include "WPILib.h"

class IrCheck: public CommandBase
{
public:
	int Infinite;
	IrCheck();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
