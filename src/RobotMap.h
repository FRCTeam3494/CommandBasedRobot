#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

const int LEFT_MOTOR_MASTER = 4;  //1, 2, 3 are right MCs
const int LEFT_MOTOR_FOLLOWER_A = 5;
const int LEFT_MOTOR_FOLLOWER_B = 6;
const int RIGHT_MOTOR_MASTER = 1;
const int RIGHT_MOTOR_FOLLOWER_A = 2;
const int RIGHT_MOTOR_FOLLOWER_B = 3;

const int RIGHT_JOYSTICK    = 5;
const int LEFT_JOYSTICK     = 1;

//unsure about these(These are talons)
const int LEFT_LIFT = 7;
const int RIGHT_LIFT = 8;

<<<<<<< HEAD
const int LEFT_ROLLER = 0;
const int RIGHT_ROLLER = 1;

const int compressor_int = 0;

const int Solenoid_Roller = 1;
const int Solenoid_Shifter = 2;
const int Solenoid_Pusher = 3;

=======
const int PUSHER_RIGHT = 0;
const int PUSHER_LEFT = 1;
>>>>>>> origin/practice_robot

#endif
