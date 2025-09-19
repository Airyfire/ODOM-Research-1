// Purpose: to declare all global variables that will be used in the program
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "api.h"

//drivetrain motors
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;

//odom rotation sensors
extern pros::Rotation perpendicular;
extern pros::Rotation parallel;

//odom inertial sensor
extern pros::Imu inertial_sensor;

// intake motors
extern pros::Motor top_motor;
extern pros::Motor mid_goal_motor;
extern pros::Motor bottom_goal_motor;