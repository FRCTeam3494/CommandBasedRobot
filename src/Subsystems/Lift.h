#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Lift: public Subsystem {
private:
	CANTalon* talonLeft;
	CANTalon* talonRight;


	DigitalInput* limitSwitchDown;
	//DigitalInput* limitSwitchUp;
	//double rightVoltage;
	//double leftVoltage;



	//double leftMeters;
	//double rightMeters;
	bool mode;

	DoubleSolenoid* Clip;
	DoubleSolenoid* Clip_;
	float power;


public:
	Lift();
	void InitDefaultCommand();

	void MovePusher(float speed);

	void ChangeMode(bool fast);
	//positive: move up
	//negative: move down
	void move(float magnitude);
	void L_Sol_Set();
	void L_Sol_Off();
	void H_Sol_Set();
	void H_Sol_Off();
	bool limit;


};

#endif

