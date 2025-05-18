#include "globals.hpp"
#include <cmath>


extern int PID_task(); // PID task function declaration
extern void move_to_pos(double x, double y, double target_angle); // move_to_pos function declaration
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

extern double kP; // kP variable declaration
extern double kI; // kI variable declaration
extern double kD; // kD variable declaration
extern double kP_turn; // kP_turn variable declaration
extern double kI_turn; // kI_turn variable declaration
extern double kD_turn; // kD_turn variable declaration