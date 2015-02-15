#include "CommandBase.h"
<<<<<<< HEAD

=======
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Lift.h"
#include "Commands/Scheduler.h"
#include "Subsystems/Kompressor.h"
>>>>>>> origin/practice_robot

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::driveTrain = NULL;
OI* CommandBase::oi = NULL;
Lift* CommandBase::lift = NULL;
<<<<<<< HEAD
Rollers* CommandBase::roller = NULL;
Kompressor* CommandBase::kompressor = NULL;
Solenoids* CommandBase::solenoids = NULL;
=======
Kompressor* CommandBase::kompressor = NULL;
Pusher* CommandBase::pusher = NULL;
>>>>>>> origin/practice_robot

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
<<<<<<< HEAD
	roller = new Rollers();
	kompressor = new Kompressor();
	solenoids = new Solenoids();
=======
	kompressor = new Kompressor();
	pusher = new Pusher();
// twerk
>>>>>>> origin/practice_robot
}
