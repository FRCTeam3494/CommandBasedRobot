#ifndef Solenoid_Pusher_Set_H
#define Solenoid_Pusher_Set_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/Rollers.h"

class Solenoid_Pusher_Set: public CommandBase
{
public:
	Solenoid_Pusher_Set(bool solenoid_pusher);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float pusher_set;
};

#endif
