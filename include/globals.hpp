// Purpose: to declare all global variables that will be used in the program
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "api.h"

//drivetrain motors
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;

//odom Encoders
extern pros::adi::Encoder Lateral;
extern pros::adi::Encoder Strafe;

//odom inertial sensor
extern pros::Imu inertial_sensor;