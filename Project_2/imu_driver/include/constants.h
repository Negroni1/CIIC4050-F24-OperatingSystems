#ifndef CONSTANTS_H
#define CONSTANTS_H

// Struct representing a Robot with its properties
struct Robot {
  double time;   // Time in seconds
  double p_x;    // Position on x-axis
  double p_y;    // Position on y-axis
  double v_x;    // Velocity on x-axis
  double v_y;    // Velocity on y-axis
  double acc_x;  // Acceleration on x-axis
  double acc_y;  // Acceleration on y-axis
};

// Declare an external instance of the Robot struct and a write flag
extern struct Robot robot;
extern int write_flag;

#endif  // CONSTANTS_H
