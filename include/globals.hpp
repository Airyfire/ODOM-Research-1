// Purpose: to declare all global variables that will be used in the program
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "api.h"
#include <initializer_list>

//drivetrain motors
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;

//odom rotation sensors
extern pros::Rotation Strafe;
extern pros::Rotation Lateral;

//odom inertial sensor
extern pros::Imu inertial_sensor;