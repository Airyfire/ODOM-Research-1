#include "main.h"
#include <cstdlib>
#include "globals.hpp"
#include "ODOM.hpp"
#include "pros/misc.hpp"
#include "pros/rotation.hpp"



void initialize() {
	pros::lcd::initialize();
	pros::Task odom([](void*) { odom_task(); }, (void *)"odom_task");
	pros::lcd::print(0, "Reset in odom_task: %d", Strafe.get_position());
	pros::delay(1000);
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


		pros::delay(20);
	}
}
 