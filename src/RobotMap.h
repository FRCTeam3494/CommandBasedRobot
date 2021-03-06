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

const int LEFT_MOTOR_MASTER = 5;  //1, 2, 3 are right MCs
const int LEFT_MOTOR_FOLLOWER_A = 6;
const int LEFT_MOTOR_FOLLOWER_B = 7;
const int RIGHT_MOTOR_MASTER = 1;
const int RIGHT_MOTOR_FOLLOWER_A = 2;
const int RIGHT_MOTOR_FOLLOWER_B = 3;


const int RIGHT_JOYSTICK    = 5;
const int LEFT_JOYSTICK     = 1;

//unsure about these
const int LEFT_LIFT = 8;
const int RIGHT_LIFT = 4;

const int FIRST_CONTROLLER = 0;
const int SECOND_CONTROLLER = 1;

const int LEFT_ROLLER = 4;
const int RIGHT_ROLLER = 1;

const int COMPRESSOR = 0;

const int SOL_ROLLER_1 = 0;
const int SOL_ROLLER_2 = 1;
const int SOL_SHIFT_1 = 3;
const int SOL_SHIFT_2 = 4;
const int SOL_PUSH = 5;

const int LEFT_LIFT_LIMIT = 0;

#endif
