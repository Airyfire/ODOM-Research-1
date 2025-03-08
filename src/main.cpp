#include "main.h"
#include "globals.hpp"
#include "ODOM.cpp"
#include "pros/misc.hpp"


void initialize() {
	pros::lcd::initialize();
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
		pros::lcd::print(1, "Lateral: %lf, Strafe: %lf", Lateral.get_position(), Strafe.get_position());
////////////////////////////////////////////////////////////////
		pros::lcd::print(2, "X: %f, Y: %f, Theta: %f", x_pos, y_pos, theta);

	
		pros::delay(20);
	}
}
