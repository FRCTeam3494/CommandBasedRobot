#ifndef Kompressor_Kompress_H
#define Kompressor_Kompress_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Kompressor.h"

class Kompressor_Kompress: public CommandBase
{
public:
	Kompressor_Kompress();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
