#ifndef Compressor_Closed_Loop_H
#define Compressor_Closed_Loop_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Kompressor.h"

class Compressor_Closed_Loop: public CommandBase
{
public:
	Compressor_Closed_Loop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();


};

#endif
