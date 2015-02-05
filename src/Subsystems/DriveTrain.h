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
	CANTalon* talonLeftFollower;
	CANTalon* talonRightMaster;
	CANTalon* talonRightFollower;

public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(float leftAxis, float rightAxis);

	Gyro* gyro;
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
