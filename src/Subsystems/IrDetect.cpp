#include "IrDetect.h"
#include "../RobotMap.h"

IrDetect::IrDetect() :
		Subsystem("IrDetect")
{
	Optical0 = new DigitalInput(0);
	OpticalState = TRUE;

}

void IrDetect::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void IrDetect::IrCheck();

