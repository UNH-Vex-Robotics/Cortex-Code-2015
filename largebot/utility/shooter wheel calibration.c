#pragma config(Sensor, in2,    BallSensor,     sensorReflection)
#pragma config(Sensor, dgtl1,  LiftSonar,      sensorNone)
#pragma config(Sensor, dgtl9,  Shooter,        sensorDigitalOut)
#pragma config(Sensor, dgtl3,  WinchRaised,     sensorTouch)
#pragma config(Sensor, dgtl4,  WinchEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           WinchLeft,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Belt,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           FlyLeft1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           FlyLeft2,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           FlyLeft3,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           FlyRight3,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           FlyRight2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           FlyRight1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           IntakeFunnel,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          WinchRight,    tmotorVex393_HBridge, openLoop, reversed)


#include "../largebot_control.h"
#include "../largebot_autonomy.h"
#include "../shooter.h"

#include "../largebot_control.c"
#include "../largebot_autonomy.c"
#include "../shooter.c"

int target();


task main()
{
	while(true){


}
