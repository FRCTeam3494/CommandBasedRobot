#include "DriveBase_Command_Group.h"
#include "Commands/Compressor_Closed_Loop.h"
#include "Commands/Drive/Drive.h"

DriveBase_Command_Group::DriveBase_Command_Group()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.



	//AddParallel(new Compressor_Closed_Loop());
	//AddParallel(new Drive());

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
