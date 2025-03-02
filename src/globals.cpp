#include "api.h"
#include "globals.hpp"


//drivetrain motors
pros::MotorGroup left_mg({20, -12, 13});
pros::MotorGroup right_mg({-17, 18, -19});

//odom Encoders
pros::adi::Encoder Lateral(3,4, false);
pros::adi::Encoder Strafe('a', 'b', false);

