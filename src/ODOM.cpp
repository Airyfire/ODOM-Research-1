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
    //initializing variables
    double lat_ticks = 0;
    double strafe_ticks = 0;
    double final_theta = 0;

    //conversion to inches
    double delta_y = 0;
    double delta_x = 0;
    
    //change in heading in radians
    double delta_theta = 0;

    while (true) {
        //get current sensor values
        lat_ticks = Lateral.get_value();
        strafe_ticks = Strafe.get_value();
        final_theta = inertial_sensor.get_yaw();

        //convert to inches
        delta_y = ticksToInches(lat_ticks);
        delta_x = ticksToInches(strafe_ticks);

        //change in heading in radians
        delta_theta = (final_theta * RADIANS) - theta;

        //update global position
        x_pos += (delta_x * cos(theta)) - (delta_y * sin(theta));
        y_pos += (delta_x * sin(theta)) + (delta_y * cos(theta));
        theta += delta_theta;

        pros::delay(20);
    }
}
