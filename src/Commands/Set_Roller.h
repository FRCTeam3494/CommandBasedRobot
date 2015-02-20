#ifndef Set_Roller_H
#define Set_Roller_H

#include "../CommandBase.h"
#include "../Subsystems/Rollers.h"
#include "WPILib.h"

class Set_Roller: public CommandBase
{
public:
	Set_Roller(float _on_roller);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float on_roller;
};

#endif
