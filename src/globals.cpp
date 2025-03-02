#include "globals.hpp"


//drivetrain motors
pros::MotorGroup left_mg({20, -12, 13});
pros::MotorGroup right_mg({-17, 18, -19});

//odom Encoders
pros::adi::Encoder Lateral('C','D', false);
pros::adi::Encoder Strafe('A', 'B', false);

//odom inertial sensor
pros::Imu inertial_sensor(11);

