#include "globals.hpp"
#include "pros/rotation.hpp"


//drivetrain motors
pros::MotorGroup left_mg({15,-16,17});
pros::MotorGroup right_mg({-1,2,-3});

//odom Encoders
pros::Rotation perpendicular(12);
pros::Rotation parallel(14);


//odom inertial sensor
pros::Imu inertial_sensor(11);

// intake motors
pros::Motor top_motor(10);
pros::Motor mid_goal_motor(6);
pros::Motor bottom_goal_motor(9);

