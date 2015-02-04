#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	controller = new Joystick(1);
}

float OI::GetLeftJoystick() {
	controller->GetRawAxis(1);
}

float OI::GetRightJoystick() {
	controller->GetRawAxis(2);
}

/*#include "OI.h"
#include "Commands/Print.h"
#include "Commands/Drive.h"

OI::OI()
{
	// Process operator interface input here.

	controller = new Joystick(1);

	 	buttonA = new JoystickButton(controller, 1);
		buttonB = new JoystickButton(controller, 2);
		buttonX = new JoystickButton(controller, 3);
		buttonY = new JoystickButton(controller, 4);
		buttonLB = new JoystickButton(controller, 5);
		buttonRB = new JoystickButton(controller, 6);
		buttonStart = new JoystickButton(controller, 8);
		buttonSelect = new JoystickButton(controller, 7);

		buttonA->WhenPressed(new Print());
		buttonX->WhenPressed(new Drive());
}
*/
