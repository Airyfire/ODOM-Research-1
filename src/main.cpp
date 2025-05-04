#include "main.h"
#include <cstdlib>
#include "globals.hpp"
#include "ODOM.hpp"
#include "pros/misc.hpp"
#include "pros/rotation.hpp"
#include "PID.hpp"



void initialize() {
	pros::lcd::initialize();
	pros::Task odom([](void*) { odom_task(); }, (void *)"odom_task");

	pros::Task pid([](void*) { PID_task(); }, (void *)"PID_task");
	pros::delay(1000);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	while (true) {
		enable_drivePID = true; // Enable PID control for manual operation	
		// Drive Control (tank drive)
		
////////////////////////////////////////////////////////////////
		//Odom test


		pros::delay(20);
	}
}
 