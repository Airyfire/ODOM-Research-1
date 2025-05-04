#include "ODOM.hpp"
#include "globals.hpp"

#define WHEEL_DIAMETER 2.75
#define GEAR_RATIO 1.0
#define TRACK_WIDTH 0.0 // Distance between the left and right wheels in inches

bool enable_drivePID = false; // Flag to enable or disable the PID controller

double target = 0.0;
double direction = 0.0;

double computeYawError() {
	// Get the current yaw from the inertial sensor (in degrees)
	double currentYaw = inertial_sensor.get_rotation();

	// Normalize yaw to the range -180 to 180 degrees (to handle wraparound errors)
	double yawError = direction - currentYaw;

	// Normalize to [-180, 180] range to avoid large errors
	if (yawError > 180.0) {
		yawError -= 360.0;
	} else if (yawError < -180.0) {
		yawError += 360.0;
	}

	return yawError;  // Return the error in degrees
}

int PID_task(){
	// Initialize PID variables
	double error = 0;
	double integral = 0;
	double derivative = 0;
	double lastError = 0;
	double turn_error = 0;
	double turn_integral = 0;
	double turn_derivative = 0;
	double turn_lastError = 0;

	while (true) {
		if (enable_drivePID) {
			// Calculate the error between the target and current position
			error = target - sqrt(pow(delta_x_rotated, 2) + pow(delta_y_rotated, 2));
			integral += error; // Accumulate the integral term
			derivative = error - lastError; // Calculate the derivative term
			lastError = error; // Update last error for next iteration

			// Calculate the turn error using the computeYawError function
			turn_error = computeYawError();
			turn_integral += turn_error; // Accumulate the integral term for turning
			turn_derivative = turn_error - turn_lastError; // Calculate the derivative term for turning
			turn_lastError = turn_error; // Update last error for next iteration

			pros::lcd::print(0, "Error: %f", error); // Print the error to the LCD
			pros::lcd::print(1, "Turn Error: %f", turn_error); // Print the turn error to the LCD
			pros::lcd::print(2, "X Position: %f", x_pos); // Print the X position to the LCD
			pros::lcd::print(3, "Y Position: %f", y_pos); // Print the Y position to the LCD
			pros::delay(20); // Delay to prevent overloading the CPU
		}
	}
	return 0; // Return success
}


