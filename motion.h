#pragma once
#include "Motor.h"

// header file for characters.cpp to use to be able to call certain functions

// shared variables
extern Motor leftMotor;
extern Motor rightMotor;

// functions for movement
void move_backward(float seconds);
void move_forward(float seconds);
void turn_left(float degrees);
void turn_right(float degrees);

// functions for pen control
void raise_pen();
void lower_pen();
