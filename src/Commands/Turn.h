#ifndef TURN_H
#define TURN_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/DriveTrain.h"

class Turn: public CommandBase
{
public:
	Turn(float _angle, float _speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float angle;
	float speed;
	bool slow;
};

#endif
