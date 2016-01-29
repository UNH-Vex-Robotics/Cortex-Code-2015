ragma config(Motor,  port10, leftMotor,    tmotorVex393_HBridge, openLoop, openLoop)
#pragma config(Motor,  port1,  rightMotor,   tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Sensor, in1,    lfCenter,          sensorLineFollower)
#pragma config(Sensor, in2,    lfRight,          sensorLineFollower)
#pragma config(Sensor, in3,    lfLeft,          sensorLineFollower)
/* Code made by ethan */

#define LEFT 1
#define RIGHT 0

#define STRAIGHT  50
#define TURN_HIGH 60
#define TURN_LOW  30
#define SPIN_HIGH 50
#define SPIN_LOW   0

int lineout[2][8] = {
	{SPIN_HIGH,  SPIN_LOW},  // 0 0 0
	{TURN_HIGH,  TURN_LOW},  // 0 0 1
	{STRAIGHT,   STRAIGHT},  // 0 1 0
	{TURN_LOW,   STRAIGHT},  // 0 1 1
	{TURN_LOW,   TURN_HIGH}, // 1 0 0
	{SPIN_HIGH,  SPIN_LOW},  // 1 0 1
	{TURN_LOW,   TURN_HIGH}, // 1 1 0
	{SPIN_HIGH,  SPIN_LOW},  // 1 1 1
};

task main() {
	while(true) {
		int lines = (SensorValue(lfLeft) < 500) << 2 | (SensorValue(lfCenter) < 500) << 1 | (SensorValue(lfRight) < 500);

		motor[leftMotor]  = lineout[LEFT][lines];
		motor[rightMotor] = lineout[RIGHT][lines];
	}
}
