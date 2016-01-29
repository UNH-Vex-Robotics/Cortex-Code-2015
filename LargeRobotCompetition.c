#pragma config(Sensor, in1,    BallSensor,     sensorReflection)
#pragma config(Sensor, dgtl1,  LiftSonar,      sensorSONAR_raw)
#pragma config(Sensor, dgtl2,  Shooter,        sensorDigitalOut)
#pragma config(Sensor, dgtl3,  LiftRaised,     sensorTouch)
#pragma config(Sensor, dgtl4,  LiftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,  WinchLeft,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,  Belt,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,  FlyLeft1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,  FlyLeft2,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,  FlyLeft3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,  FlyRight3,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,  FlyRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,  FlyRight1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,  IntakeFunnel,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10, WinchRight,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

#include "largebot_control.h"

void pre_auton() {
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

}

task autonomous() {
}

task usercontrol() {
	while (true) {
		shooter_motor_set(vexRT[Ch3]);
		// 6u -> shooter
		/*
		7u shooter start
		7d shooter stop
		7r decrese speed (by 1)
		7l increase speed (by 1)

		8u hold winch up
		8d hold winch dpwm

		5u toggle belts + intake on
		5d toggle belts + intake reverse
		*/
		;
	}
}

#include "largebot_control.c"
