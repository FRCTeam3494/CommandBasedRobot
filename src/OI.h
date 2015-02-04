#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* controller;
public:
	OI();
	float GetLeftJoystick();
	float GetRightJoystick();
};

#endif
