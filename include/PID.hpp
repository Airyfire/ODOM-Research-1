#include "globals.hpp"
#include <cmath>


extern int PID_task(); // PID task function declaration
extern void move_to(double target_distance, double target_angular); // move_to function declaration
extern double computeYawError(); // computeYawError function declaration
extern bool enable_drivePID; // enable_drivePID variable declaration

extern int error; // error variable declaration
extern int integral; // integral variable declaration
extern int derivative; // derivative variable declaration
extern int lastError; // lastError variable declaration
extern int turn_error; // turn_error variable declaration
extern int turn_integral; // turn_integral variable declaration
extern int turn_derivative; // turn_derivative variable declaration

extern int turn_lastError; // turn_lastError variable declaration
extern double target; // target variable declaration
extern double direction; // direction variable declaration

