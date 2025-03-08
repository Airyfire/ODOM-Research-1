#include "main.h"
#include "globals.hpp"
#include "ODOM.cpp"


void initialize() {
	Strafe.reset(); // Reset the encoder
	Lateral.reset(); // Reset the encoder
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	while (true) {
		// Drive Control (tank drive)
		
////////////////////////////////////////////////////////////////
		//Odom test
		pros::lcd::print(1, "Lateral: %d, Strafe: %d", Lateral.get_value(), Strafe.get_value());
////////////////////////////////////////////////////////////////
		pros::lcd::print(2, "X: %f, Y: %f, Theta: %f", x_pos, y_pos, theta);
		pros::delay(20);
	}
}
