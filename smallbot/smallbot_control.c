//#include "smallbot_control.h"

/* Motors */
void motor_set(int right, int left){
	motor[RightDriveMotorCenter] = right;
	motor[RightDriveMotorFront]  = right;
	motor[RightDriveMotorMiddle] = right;
	motor[RightDriveMotorRear]   = right;

	motor[LeftDriveMotorCenter] = left;
	motor[LeftDriveMotorFront]  = left;
	motor[LeftDriveMotorMiddle] = left;
	motor[LeftDriveMotorRear]   = left;
}

int motor_get_left_encoder(){ return nMotorEncoder(LeftDriveMotorMiddle); }
int motor_get_right_encoder(){ return nMotorEncoder(RightDriveMotorMiddle); }

/* Drive Encoder */
float drive_encoder_to_inches (int encoder_value){
	return ((DRIVE_WHEEL_CIRC*encoder_value)/360.0);
}

int inches_to_drive_encoder (float inches){
	return ((inches*360.0)/DRIVE_WHEEL_CIRC);
}

float drive_encoder_to_degrees (int encoder_value){
	return (encoder_value*(360/1308));
}

int degrees_to_drive_encoder (float degrees_value){
	return (degrees_value*(1308/360)) * 1.13; // add scaling factor because we are undershooting a little
}

/* Gyro */
int get_gyro(){
	return SensorValue(ChassisGyro);
}

float get_gyro_degrees(){
	return gyroTicksToDegrees(getGyro());
}

int gyro_degrees_to_ticks(float deg){
	return deg * GYRO_TICKS_PER_DEGREE;
}

float gyro_ticks_to_degrees(int ticks){
	return ticks / GYRO_TICKS_PER_DEGREE;
}

/* Intake */
void intake_set(int speed){
	motor[Intake]  = speed;
}

void top_intake_set(int speed){
	motor[TopIntake] = speed;
}

/* Bumper Switches */
int bumperswitch_get_left(){ return !SensorValue[LeftRearBumper]; }
int bumperswitch_get_right(){ return !SensorValue[RightRearBumper]; }

/* Line Sensors */
linestate linetracker_get(){
	return (SensorValue(RightLineFollow)  > LINE_THRESH) |
	       (SensorValue(MiddleLineFollow) > LINE_THRESH) << 1 |
	       (SensorValue(LeftLineFollow)   > LINE_THRESH) << 2;
}

