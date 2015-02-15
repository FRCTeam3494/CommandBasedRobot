#include "Kompressor.h"
#include "../RobotMap.h"
#include "Commands/Kompressor_Kompress.h"

Kompressor::Kompressor() :
		Subsystem("Kompressor")
{
	compressor = new Compressor(compressor_int);
	compressor->SetClosedLoopControl(true);



}

void Kompressor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Kompressor_Kompress());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Kompressor::Kompressor_Start()
{
	compressor->Start();



}

void Kompressor::Kompressor_Stop()
{

compressor->Stop();

}


void Kompressor::Kompressor_Closed_Loop(bool on)
{

compressor->SetClosedLoopControl(on);
}







bool Kompressor::PressureSwitchState()
{

	return compressor->GetPressureSwitchValue();

}
