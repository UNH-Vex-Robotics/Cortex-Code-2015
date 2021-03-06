#pragma config(Sensor, in2,    BallSensor,     sensorReflection)
#pragma config(Sensor, dgtl1,  LiftSonar,      sensorSONAR_mm)
#pragma config(Sensor, dgtl3,  WinchRaised,    sensorTouch)
#pragma config(Sensor, dgtl4,  WinchEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Shooter,        sensorDigitalOut)
#pragma config(Motor,  port1,           WinchLeft,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           Belt,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           FlyLeft1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           FlyLeft2,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           FlyLeft3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           FlyRight3,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           FlyRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           FlyRight1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           IntakeFunnel,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          WinchRight,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(45)
#pragma userControlDuration(75)

#include "largebot_control.h"
#include "largebot_autonomy.h"
#include "shooter.h"

void pre_auton() {
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

}

task autonomous() {
	int shots_taken = 0;

	intake_set(0);
	belt_set(0);

	shooter_set_target_speed(84);
	shooter_motor_set(84);

	int state = 0;
	// 0 -> waiting for robot to be touching
	// 1 -> droping hook
	// 2.5 -> waiting for robot to move forward
	// 3 -> up, up, up and away

	int winch_start = winch_get_encoder();
	int wait_time;

	const int WINCH_DIST_TO_HOOK = 620;

	while (true) {
		shots_taken += auto_shoot();
		if(!state && SensorValue[LiftSonar] < 40){
			winch_set(WINCH_DOWN_SPEED); // backwards
			state++;
	  } else if (state == 1){
	    if(winch_get_encoder() - winch_start > WINCH_DIST_TO_HOOK){
	    	state++;
	    	winch_set(0);
	    	wait_time = nSysTime;
	    }
		} else if (state == 2){
		//} else if (state == 2 && SensorValue[LiftSonar] > 55 && SensorValue[LiftSonar] < 140){
			state++;
			winch_set(WINCH_UP_SPEED);
    	shooter_motor_set(120);
		} else if(state == 3){
		  if(winch_at_top() || SensorValue[WinchRaised]){
	    	winch_set(0);
	    	state++;
		  }
	  } else if(state == 4){
	    // hopefully we win!!!
	  	shooter_motor_set(103);
	  }
	}
}

task usercontrol() {
	int shots_taken = 0;

	//shooter_set_target_speed(84);
	shooter_motor_set(89);

	while (true) {
		//shots_taken += auto_shoot();
		// 6u -> shooter
		if(vexRT[Btn6U])
			set_pneumatics(true); // NOTE !!! THIS WILL NOT PLAY NICE WITH THE auto_shoot function!!! You have been warned

		shooter_increment_speed(vexRT[Btn7R]); // NOTE !!! THIS WILL NOT PLAY NICE WITH THE auto_shoot function!!! You have been warned
		shooter_decrement_speed(vexRT[Btn7L]); // NOTE !!! THIS WILL NOT PLAY NICE WITH THE auto_shoot function!!! You have been warned

		if(vexRT[Btn7L])
			shooter_motor_set(89);
		else if(vexRT[Btn7U])
			shooter_motor_set(0);

		winch_set(vexRT[Btn8U] * -WINCH_UP_SPEED + vexRT[Btn8D] * WINCH_UP_SPEED); // yes, this does NOT ues WINCH_DOWN_SPEED, because then there would be a posibilty that both buttons -> movement

		if(vexRT[Btn5U] || vexRT[Btn5D]){
			belt_set(vexRT[Btn5U] * BELT_SPEED + vexRT[Btn5D] * -BELT_SPEED);
			intake_set(vexRT[Btn5U] * INTAKE_SPEED + vexRT[Btn5D] * -INTAKE_SPEED);
		}
	}
}

#include "largebot_control.c"
#include "largebot_autonomy.c"
#include "shooter.c"
