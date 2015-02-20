#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* talonLeftMaster;
	CANTalon* talonLeftFollowerA;
	CANTalon* talonLeftFollowerB;
	CANTalon* talonRightMaster;
	CANTalon* talonRightFollowerA;
	CANTalon* talonRightFollowerB;

	DoubleSolenoid* solenoid_Shifter;


public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(float leftAxis, float rightAxis);
	float GetAngle();
	void ResetGyro();
	void ChangeGear(bool _gear);
	Gyro* gyro;

private:

	bool currentGear;
	//true is low gear and false is second gear(numbers are too hard for me)


};

#endif

/*#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveTrain();
	void InitDefaultCommand();

	CANTalon* talon_1;
	CANTalon* talon_2;
	CANTalon* talon_3;
	CANTalon* talon_4;


	void TankDrive(float leftAxis, float rightAxis);
};

#endif
*/
