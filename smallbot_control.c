
void motor_set(int left, int right){
	motor[RightDriveMotorFront]  = right;
	motor[RightDriveMotorMiddle] = right;
	motor[RightDriveMotorRear]   = right;

	motor[LeftDriveMotorFront]  = left;
	motor[LeftDriveMotorMiddle] = left;
	motor[LeftDriveMotorRear]   = left;
}

void intake_set(int speed){
	motor[RightIntake] = speed;
	motor[LeftIntake]  = speed;
}

void pusher_set(int speed){
	motor[PusherRightMotor] = speed;
	motor[PusherLeftMotor]  = speed;
}

int motor_get_left_encoder(){ return nMotorEncoder(LeftDriveMotorMiddle); }
int motor_get_right_encoder(){ return nMotorEncoder(RightDriveMotorMiddle); }

int pusher_get_left_encoder(){ return SensorValue(PusherLeftEncoder); }
int pusher_get_right_encoder(){ return SensorValue(PusherRightEncoder); }
int pusher_get_home_switch(){ return SensorValue(PusherHomeLimit); }

int bumperswitch_get_left(){ return SensorValue(LeftRearBumper); }
int bumperswitch_get_right(){ return SensorValue(RightRearBumper); }

linestate linetracker_get(){
	return (SensorValue(RightLineFollow)  > LINE_THRESH) |
	       (SensorValue(MiddleLineFollow) > LINE_THRESH) << 1 |
	       (SensorValue(LeftLineFollow)   > LINE_THRESH) << 2;
}
