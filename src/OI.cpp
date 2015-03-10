
#include "OI.h"
#include "RobotMap.h"

#include "Commands/Set_Roller.h"
#include "Commands/Lifting.h"
#include "Commands/Compressor_Closed_Loop.h"

#include "Commands/Compressor_Closed_Loop.h"
#include "Commands/Solenoid_Roller_Set.h"

#include "Commands/ResetEncoders.h"
#include "Commands/Autonomous/Autonomous_Move.h"


#include "Commands/Print.h"
#include "Commands/Drive/Cut_Power.h"
//Drive/ Folder

#include "Commands/Autonomous/Turn.h"
#include "Commands/Drive/ShiftGear.h"
#include "Subsystems/DriveTrain.h"

//
OI::OI() {
	// Process operator interface input here.
	controller = new Joystick(FIRST_CONTROLLER);
	controller_2 = new Joystick(SECOND_CONTROLLER);

/**
 * XBOX 360 Axes:
 * 1: Left Y Axis
 * 2: Left Trigger
 * 3: Right Trigger
 * 5: Right Y Axis
 */

buttonA = new JoystickButton(controller, 1);
buttonB = new JoystickButton(controller, 2);
buttonX = new JoystickButton(controller, 3);
buttonY = new JoystickButton(controller, 4);
buttonLB = new JoystickButton(controller, 5);
buttonRB = new JoystickButton(controller, 6);
buttonStart = new JoystickButton(controller, 8);
buttonSelect = new JoystickButton(controller, 7);

buttonA_2 = new JoystickButton(controller_2, 1);  //  xbox or whats
buttonB_2 = new JoystickButton(controller_2, 2);
buttonX_2 = new JoystickButton(controller_2, 3);
buttonY_2 = new JoystickButton(controller_2, 4);
buttonLB_2 = new JoystickButton(controller_2, 5);
buttonRB_2 = new JoystickButton(controller_2, 6);
buttonStart_2 = new JoystickButton(controller_2, 8);
buttonSelect_2 = new JoystickButton(controller_2, 9);

//open
buttonA->WhenPressed(new Solenoid_Roller_Set(false));

//close
buttonY->WhenPressed(new Solenoid_Roller_Set(true));

//gear down
buttonX->WhenPressed(new ShiftGear(true));

//gear up
buttonB->WhenPressed(new ShiftGear(false));


buttonSelect->WhenPressed(new Cut_Power());
buttonStart_2->WhenPressed(new ResetEncoders());
buttonSelect_2->WhenPressed(new Compressor_Closed_Loop());



}

float OI::GetLeftJoystick() {
	return 1 * controller->GetRawAxis(1);
}

float OI::GetRightJoystick() {
	return -1 * controller->GetRawAxis(5);
}


float OI::GetLeftTrigger() {
	return controller->GetRawAxis(2);
}

float OI::GetRightTrigger(){
	return controller->GetRawAxis(3);
}
float OI::GetLeftTrigger_2() {
	return controller_2->GetRawAxis(2);
}

float OI::GetRightTrigger_2(){
	return controller_2->GetRawAxis(3);
}

float OI::GetLeftBumper(){
	return controller->GetRawButton(5);
}

float OI::GetRightBumper(){
	return controller->GetRawButton(6);
}







/*#include "OI.h"
 #include "Commands/Print.h"
 #include "Commands/Drive.h"

 OI::OI()
 {
 // Process operator interface input here.

 controller = new Joystick(1);


 }
 */
