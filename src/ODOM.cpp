/*
#include "globals.hpp"
#include <cmath>


//robot positions
double x_pos = 0;
double y_pos = 0;
double theta = 0;

double perpendicular_inch = 0; // odom pod perpendicular to wheels of chassis
double parallel_inch = 0; // odom pod parallel to wheels of chassis

double dx = 0;
double dy = 0;

// defining constants for odom
#define WHEEL_DIAMETER 2.75
#define DEG_PER_REV 360.0
#define DIST_FROM_CENT_PARALLEL 2.5 //inches
#define DIST_FROM_CENT_PERPENDICULAR 2.0 //inches
#define RADIANS (M_PI/180.0)
// ticks to inches converter
double degtoinch(double degrees) {
    // Convert centidegrees to inches
    return (degrees / DEG_PER_REV) * WHEEL_DIAMETER * M_PI;
}

void reset_odom(){
    // Reset the odometry sensors to zero
    perpendicular.reset();
    parallel.reset();
    inertial_sensor.reset();
    pros::delay(50); // Delay to ensure sensors are reset
    perpendicular_inch = 0;
    parallel_inch = 0;
    x_pos = 0;
    y_pos = 0;
    theta = 0;
}

void update_odom(){
    // First things first, set previous values to previous current values
    double prev_perpendicular = perpendicular_inch;
    double prev_parallel = parallel_inch;

    // Get the current values from odom sensors in inches
    perpendicular_inch = degtoinch(perpendicular.get_position());
    parallel_inch = degtoinch(parallel.get_position());

    // get theta in radians
    theta = inertial_sensor.get_rotation() * RADIANS;

    // Use formulas for y coordinate: y = 2((dy/theta) + dist_from_cent_parallel)(sin(theta/2))
    dy = parallel_inch - prev_parallel;
    y_pos += 2 * ((dy/theta) + DIST_FROM_CENT_PARALLEL) * sin(theta/2);

    // Use formulas for x coordinate: x = 2((dx/theta) + dist_from_cent_perpendicular)(sin(theta/2))
    dx = perpendicular_inch - prev_perpendicular;
    x_pos += 2 * ((dx/theta) + DIST_FROM_CENT_PERPENDICULAR) * sin(theta/2);



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
*/