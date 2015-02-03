#ifndef OI_H
#define OI_H


#include "WPILib.h"


class OI
{
private:

public:
	OI();
	//declare the contoller
	Joystick* controller;
	JoystickButton* buttonA;
	JoystickButton* buttonB;
	JoystickButton* buttonX;
	JoystickButton* buttonY;
	JoystickButton* buttonLB;
	JoystickButton* buttonRB;
	JoystickButton* buttonStart;
	JoystickButton* buttonSelect;

};

#endif
