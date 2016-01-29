#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    PowerExpander,  sensorAnalog)
#pragma config(Sensor, in6,    RightLine,      sensorLineFollower)
#pragma config(Sensor, in7,    MiddleLine,     sensorLineFollower)
#pragma config(Sensor, in8,    LeftLine,       sensorLineFollower)
#pragma config(Sensor, dgtl4,  PusherEncoderRight,   sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  PusherEncoderLeft,    sensorQuadEncoder)
#pragma config(Sensor, dgtl12, PusherHomeLimit,          sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           RightPush,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           RightFront,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           RightMiddle,   tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_1)
#pragma config(Motor,  port4,           RightRear,     tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           RightIntake,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LeftFront,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           LeftMiddle,    tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_2)
#pragma config(Motor,  port8,           LeftRear,      tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port9,           LeftIntake,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          LeftPush,      tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

#include "Vex_Competition_Includes.c"   // Main competition background code...do not modify!

#include "smallbot_control.h"

void pre_auton() {
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
}

task autonomous() {
}

task usercontrol() {
while (true) {
	// Drive motors
	motor_set(vexRT[Ch2], vexRT[Ch3]);

	// Pusher
	pusher_set(vexRT[Btn5U] * PUSHER_OUT_SPEED + vexRT[Btn5D] * PUSHER_IN_SPEED);

	// Intake
	intake_set(vexRT[Btn6U] * INTAKE_IN_SPEED + vexRT[Btn6D] * INTAKE_OUT_SPEED);

}
}

#include "smallbot_control.c"
