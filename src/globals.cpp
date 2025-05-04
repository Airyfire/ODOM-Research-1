#include "globals.hpp"
#include "pros/rotation.hpp"


//drivetrain motors
pros::MotorGroup left_mg({20, -12, 13});
pros::MotorGroup right_mg({-17, 18, -19});

//odom Encoders
pros::Rotation Strafe(15);
pros::Rotation Lateral(14);


//odom inertial sensor
pros::Imu inertial_sensor(11);

