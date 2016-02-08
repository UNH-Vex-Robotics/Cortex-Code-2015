#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    PowerExpander,  sensorNone)
#pragma config(Sensor, in6,    RightLineFollow, sensorLineFollower)
#pragma config(Sensor, in7,    MiddleLineFollow, sensorLineFollower)
#pragma config(Sensor, in8,    LeftLineFollow, sensorLineFollower)
#pragma config(Sensor, dgtl4,  PusherRightEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  PusherLeftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl10, LeftRearBumper, sensorDigitalIn)
#pragma config(Sensor, dgtl11, RightRearBumper, sensorDigitalIn)
#pragma config(Sensor, dgtl12, PusherHomeLimit, sensorTouch)
#pragma config(Sensor, I2C_1,  DriveMotorLeftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  DriveMotorRightEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           RightDriveMotorCenter, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           RightDriveMotorFront, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           RightDriveMotorMiddle, tmotorVex393_MC29, openLoop, reversed, driveRight, encoderPort, I2C_1)
#pragma config(Motor,  port4,           RightDriveMotorRear, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           RightIntake,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           LeftDriveMotorFront, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           LeftDriveMotorMiddle, tmotorVex393_MC29, openLoop, driveLeft, encoderPort, I2C_2)
#pragma config(Motor,  port8,           LeftDriveMotorRear, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port9,           LeftIntake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          LeftDriveMotorCenter, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

#include "Vex_Competition_Includes.c"   // Main competition background code...do not modify!

#include "smallbot_control.h"
#include "smallbot_autonomy.h"

void pre_auton() {
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;
}

task autonomous() {
	// drive_inches(-34); works
	wait1Msec(500);
	drive_inches(28.5);

	wait1Msec(500);
	rotate_degrees_right(90);

	wait1Msec(500);
	drive_inches_slow(3);

	wait1Msec(500);
	dump_balls();

	wait1Msec(500);
	drive_inches_slow(-3);

	wait1Msec(500);
	rotate_degrees_left(135);

	wait1Msec(500);
	pickup_balls();

	wait1Msec(500);
	rotate_degrees_right(135);

	wait1Msec(500);
	drive_inches_slow(4);

	wait1Msec(500);
	// dump balls again
	dump_balls();

	wait1Msec(500);
	drive_inches_slow(-4);

  if(0){ // ignore the "hanging" part of autonomous

	wait1Msec(500);
	rotate_degrees_right(90);

	wait1Msec(500);
	drive_inches(22);

	wait1Msec(500);
	rotate_degrees_left(90);

	wait1Msec(500);
	drive_inches(24);

	wait1Msec(500);
	rotate_degrees_right(90);

	wait1Msec(500);
	reverse_until_bumpers(); // WOULD BE FUCKING AWESOME IF ROBOTC HAD FUNCTION POINTERS!
	// stay put for 4 seconds while the hook lowers!
	wait1Msec(4000);
	drive_inches_slow(2);

  }

	motor_set(0, 0);

	// do nothing; mission accomplised
	// print to LCD for bonus points?
}


task usercontrol() {
	while (true) {
		// Drive motors
		motor_set(vexRT[Ch2], vexRT[Ch3]);

		// Top intake
		top_intake_set(vexRT[Btn5D] * TOP_INTAKE_OUT_SPEED);

		// Intake
		intake_set(vexRT[Btn6U] * INTAKE_IN_SPEED + vexRT[Btn6D] * INTAKE_OUT_SPEED);
	}
}

#include "smallbot_control.c"
#include "smallbot_autonomy.c"
