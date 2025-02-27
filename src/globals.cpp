#include "api.h"

//drivetrain motors
pros::MotorGroup left_mg({20, -12, 13});
pros::MotorGroup right_mg({-17, 18, -19});

//odom Encoders
pros::adi::Encoder Lateral('c', 'd', false);
pros::adi::Encoder Strafe('a', 'b', false);
