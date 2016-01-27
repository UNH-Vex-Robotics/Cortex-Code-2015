#include "smallbot_control.h"

void motor_set(int left, int right){
	motor(RightFront)  = right;
	motor(RightMiddle) = right;
	motor(RightRear)   = right;

	motor(LeftFront)  = left;
	motor(LeftMiddle) = left;
	motor(LeftRear)   = left;
}

void intake_set(int speed){
}

void pusher_set(int speed){
}

