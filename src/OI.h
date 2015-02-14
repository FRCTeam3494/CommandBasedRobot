#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* controller;
	Joystick* controller_2;
public:
	OI();
	//this is for the first controller
	float GetLeftJoystick();
	float GetRightJoystick();
	float GetLeftTrigger();
	float GetRightTrigger();

	//this is for the secind controller
	float GetLeftJoystick_2();
	float GetRightJoystick_2();



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
