#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Lift.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::driveTrain = NULL;
OI* CommandBase::oi = NULL;
Lift* CommandBase::lift = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

	lift = new Lift();
	driveTrain = new DriveTrain();
	oi = new OI();
// twerk
}
