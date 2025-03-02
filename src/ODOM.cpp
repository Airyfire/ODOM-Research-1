#include "globals.hpp"

//robot positions
double x_pos = 0;
double y_pos = 0;
double theta = 0;

// defining constants for odom
#define WHEEL_DIAMETER 2.75
#define TICKS_PER_REV 360
#define DIST_FROM_CENT 2.5
#define RADIANS M_PI/180
// ticks to inches converter
double ticksToInches(double ticks) {
    return (ticks / TICKS_PER_REV) * WHEEL_DIAMETER * M_PI;
}

// odom task
void odomtask(){
    double prev_lat_ticks, prev_strafe_ticks = 0;

    //current sensor values
    double lat_ticks = Lateral.get_value();
    double strafe_ticks = Strafe.get_value();
    double final_theta = inertial_sensor.get_yaw();

    //conversion to inches
    double delta_y = ticksToInches(lat_ticks - prev_lat_ticks);
    double delta_x = ticksToInches(strafe_ticks - prev_strafe_ticks);
    
    //change in heading in radians
    double delta_theta = (final_theta - theta) * RADIANS;

    double global_x = delta_x * cos(theta + delta_theta/2) - delta_y * sin(theta + delta_theta/2);
    double global_y = delta_x * sin(theta + delta_theta/2) + delta_y * cos(theta + delta_theta/2);

    //update global variables
    x_pos += global_x;
    y_pos += global_y;
    theta = final_theta;

    //update previous values
    prev_lat_ticks = lat_ticks;
    prev_strafe_ticks = strafe_ticks;

    //delay
    pros::delay(20);
}
