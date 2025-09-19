#include "main.h"
#include <cstdlib>
#include "globals.hpp"
#include "ODOM.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "PID.hpp"
#include "User_Interface.hpp"
#include "Autons.hpp"



void initialize() {
	auton_selector();
	
	//pros::Task odom([](void*) { odom_task(); }, (void *)"odom_task");

	//pros::Task pid([](void*) { PID_task(); }, (void *)"PID_task");
	pros::delay(1000);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {

	//run_selected_auto();
}

void opcontrol() {

	pros::Controller master(pros::E_CONTROLLER_MASTER);

	
	bool intake_on = false;
	bool intake_reverse = false;
	bool mid_on = false;
	bool mid_reverse = false;
	bool bottom_on = false;



	while (true) {

	
		//enable_drivePID = true; // Enable PID control for manual operation	
		// Drive Control (tank drive)


		double left_power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		double right_power = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

		//drive curve left
		double positive_curve_l = 0.00609737 * std::pow(left_power, 2.04195);
		double negative_curve_l = -0.00609737 * std::pow(-left_power, 2.04195);

		//drive curve right
		double positive_curve_r = 0.00609737 * std::pow(right_power, 2.04195);
		double negative_curve_r = -0.00609737 * std::pow(-right_power, 2.04195);

		// Right and left motor control with curve
		if (left_power >= 0){
			left_mg.move(positive_curve_l);
		}
		else if(left_power < 0){
			left_mg.move(negative_curve_l);
		}

		if (right_power >= 0){
			right_mg.move(positive_curve_r);
		}
		else if(right_power < 0){
			right_mg.move(negative_curve_r);
		}
		pros::delay(20);
		/////////////////////////////////////////////////
		// Intake Control


		mid_goal_motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST); // consistent brake mode


		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
			intake_on = !intake_on; // toggle intake state
			if (intake_on){
				top_motor.move_velocity(600);
				bottom_goal_motor.move_velocity(-200);
				intake_reverse = false;
			}
			else{
				top_motor.move_velocity(0);
				bottom_goal_motor.move_velocity(0);
			}
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
			intake_reverse = !intake_reverse; // toggle intake state
			if (intake_reverse){
				top_motor.move_velocity(-600);
				bottom_goal_motor.move_velocity(200);
				intake_on = false;
			}
			else{
				top_motor.move_velocity(0);
				bottom_goal_motor.move_velocity(0);
			}
		}
		/////////////////////////////////////////////////
		// Mid Goal Control
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
			mid_on = !mid_on; // toggle intake state
			if (mid_on){
				mid_goal_motor.move_velocity(200);
				mid_reverse = false;
			}
			else{
				mid_goal_motor.move_velocity(0);
			}
		}
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
			mid_reverse = !mid_reverse; // toggle intake state
			if (mid_reverse){
				mid_goal_motor.move_velocity(-200);
				mid_on = false;
			}
			else{
				mid_goal_motor.move_velocity(0);
			}
		}
		/////////////////////////////////////////////////
		// Bottom Goal Control
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			bottom_on = !bottom_on; // toggle intake state
			if (bottom_on){
				bottom_goal_motor.move_velocity(600);
			}
			else{
				bottom_goal_motor.move_velocity(0);
			}
		}


	}
}