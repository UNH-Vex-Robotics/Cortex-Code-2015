#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in2,    BallSensor,     sensorReflection)
#pragma config(Sensor, dgtl1,  LiftSonar,      sensorNone)
#pragma config(Sensor, dgtl3,  WinchRaised,    sensorTouch)
#pragma config(Sensor, dgtl4,  WinchEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  Shooter,        sensorDigitalOut)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_5,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_6,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           WinchLeft,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Belt,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           FlyLeft1,      tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port4,           FlyLeft2,      tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port5,           FlyLeft3,      tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port6,           FlyRight3,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_6)
#pragma config(Motor,  port7,           FlyRight2,     tmotorVex393_MC29, openLoop, encoderPort, I2C_5)
#pragma config(Motor,  port8,           FlyRight1,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_4)
#pragma config(Motor,  port9,           IntakeFunnel,  tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          WinchRight,    tmotorVex393_HBridge, openLoop, reversed)



#include "../largebot_control.h"
#include "../largebot_autonomy.h"
#include "../shooter.h"


task main()
{
	int old_reading = shooter_motor_speed();
	int old_time = nSysTime;

	int output = 82; //what the motor is set to
	int target = 100; //the value currently being read


	while(true)
	{

		displayLCDNumber(0,0,output,4);
		displayLCDNumber(0,1,target,6);

		//continuously retrieve motor speed of flywheel
		shooter_motor_speed();

		int new_time = nSysTime;
		int new_reading = shooter_motor_speed();
		int curr_speed = ((new_reading - old_reading)/(new_time - old_time));

		int change = (target - curr_speed); //getting the change in speed

		//set motors to account for change in speed
		shooter_motor_set(output - (change*0.05)); //*0.05 is to convert into appropriate units

		old_time = new_time;
		old_reading = new_reading;

	}
}


#include "../largebot_control.c"
#include "../largebot_autonomy.c"
#include "../shooter.c"
