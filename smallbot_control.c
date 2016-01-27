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
	motor(RightIntake) = speed;
	motor(LeftIntake)  = speed;
}

void pusher_set(int speed){
	motor(RightPush) = speed;
	motor(LeftPush)  = speed;
}

int encoder_get(){
	SensorValue(EncoderLeft);
	SensorValue(EncoderRight);
}

int bumperswitch_get(){
	SensorValue(
	SensorValue(
}

int linetracker_get(){
	SensorValue(RightLine);
	SensorValue(MiddleLine);
	SensorValue(LeftLine);
}
