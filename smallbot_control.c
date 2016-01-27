void motor_set(int left, int right){
	motor(RightFront)  = right;
	motor(RightMiddle) = right;
	motor(RightRear)   = right;

	motor(LeftFront)  = left;
	motor(LeftMiddle) = left;
	motor(LeftRear)   = left;
}

void intake_set(int speed){
	motor(RightIntake) = speed;
	motor(LeftIntake)  = speed;
}

void pusher_set(int speed){
	motor(RightPush) = speed;
	motor(LeftPush)  = speed;
}

int motor_get_left_encoder(){ return SensorValue(MotorEncoderLeft); }
int motor_get_right_encoder(){ return SensorValue(MotorEncoderRight); }

int pusher_get_left_encoder(){ return SensorValue(PusherEncoderLeft); }
int pusher_get_right_encoder(){ return SensorValue(PusherEncoderRight); }
int pusher_get_home_switch(){ return SensorValue(PusherHomeLimit); }

int bumperswitch_get_left(){ return SensorValue(); }
int bumperswitch_get_right(){ return SensorValue(); }

linestate linetracker_get(){
	return SensorValue(RightLine)  > LINE_THREH |
	       SensorValue(MiddleLine) > LINE_THREH |
	       SensorValue(LeftLine)   > LINE_THREH;
}
