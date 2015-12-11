#pragma config(Motor,  port10, leftMotor,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port1,  rightMotor,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Sensor, in1,    lfCenter,          sensorLineFollower)
#pragma config(Sensor, in2,    lfRight,          sensorLineFollower)
#pragma config(Sensor, in3,    lfLeft,          sensorLineFollower)
/* Code made by ethan */

#define LEFT 0
#define RIGHT 1

int lineout[2][8] = {
    {50,  0}, // 0 0 0
    {60, 30}, // 0 0 1
    {50, 50}, // 0 1 0
    {30, 50}, // 0 1 1
    {30, 60}, // 1 0 0
    {50,  0}, // 1 0 1
    {30, 60}, // 1 1 0
    {50,  0}, // 1 1 1
};

task main() {
	while(true) {
                int lines = (SensorValue(lfLeft) < 500) << 2 | (SensorValue(lfCenter) < 500) << 1 | (SensorValue(lfRight) < 500);

		motor[leftMotor]   = lineOut[LEFT][lines];
		motor[rightMotor]  = lineOut[RIGHT][lines];
	}
}
