#include "globals.hpp"
#include <cmath>


//robot positions
double x_pos = 0;
double y_pos = 0;
double theta = 0;

double strafe_inch = 0;
double lateral_inch = 0;

double dx_global = 0;
double dy_global = 0;

// defining constants for odom
#define WHEEL_DIAMETER 2.75
#define DEG_PER_REV 360.0
#define DIST_FROM_CENT 2.5
#define RADIANS (M_PI/180.0)
// ticks to inches converter
double degtoinch(double degrees) {
    // Convert centidegrees to inches
    return (degrees / DEG_PER_REV) * WHEEL_DIAMETER * M_PI;
}

void update_odom(){
    // Reset the position of rotation sensors
    Strafe.reset_position(); 
    Lateral.reset_position();

    // Reset the angle of the inertial sensor
    inertial_sensor.reset();
    pros::delay(2000);
    // Get the previous positions of the strafe and lateral motors
    double prev_strafe = strafe_inch;
    double prev_lateral = lateral_inch;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Get the current position of the strafe motor
    double strafe_pos = Strafe.get_position();
    // Get the current position of the lateral motor
    double lateral_pos = Lateral.get_position();
    // Get the current angle of the inertial sensor
    theta = inertial_sensor.get_rotation() * RADIANS;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //Convert centidegrees to inches
    strafe_inch = degtoinch(strafe_pos);
    lateral_inch = degtoinch(lateral_pos);


    // Calculate the change in x and y positions
    double delta_x = strafe_inch - prev_strafe;
    double delta_y = lateral_inch - prev_lateral;

    // Calculate the change in x and y positions based on the angle
    dy_global = (delta_x * cos(int(theta)) - delta_y * sin(int(theta)));
    dy_global = (delta_x * sin(int(theta)) + delta_y * cos(int(theta)));


    // Update the robot's position
    x_pos += dx_global;
    y_pos += dy_global;


    pros::delay(20); // Delay to prevent overloading the CPU
}

int odom_task() {

    while (inertial_sensor.is_calibrating()) {
        pros::delay(20); // Wait for the inertial sensor to calibrate
    }
    while (true) {
        update_odom();
        pros::delay(20); // Delay to prevent overloading the CPU
    }
    return 0;
}