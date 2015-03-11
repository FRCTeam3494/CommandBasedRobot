#include "Autonomous_Sequence.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Autonomous/Autonomous_Move.h"
#include "Commands/Drive/ShiftGear.h"
#include "Idiot_Lift.h"
#include "Commands/Autonomous/Turn.h"
#include "Commands/Rollers/Solenoid_Roller_Set.h"

Autonomous_Sequence::Autonomous_Sequence()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
	//AddSequential(new Idiot_Turn());
	//Wait(500);

	AddSequential(new Idiot_Lift(1));
	AddParallel(new Solenoid_Roller_Set(true));
	AddSequential(new ShiftGear(false));
	//start rollers
	//move forward
	//AddSequential(new Autonimous_Roller(3));
	AddSequential(new Autonomous_Move(1,0.4));
	AddSequential(new Turn(90,0.5));
	AddSequential(new Autonomous_Move(2.85, .85));


	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
