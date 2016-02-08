//#include "smallbot_autonomy.h"

void drive_inches_speed(float inches, int speed){
	int left = motor_get_left_encoder();
	int right = motor_get_right_encoder();

	int forward = (inches > 0.0);

	int dist = inches_to_drive_encoder(inches);

	if(forward){
		motor_set(speed, speed);
		while(true){
			int newleft = motor_get_left_encoder();
			int newright = motor_get_right_encoder();

			int read_diff = (newleft - left) - (newright - right);
			if(read_diff > 20 || read_diff < -20){ // rebalance drive outputs // negative means too much right
				motor_set(speed + read_diff / 5, speed - read_diff / 5);
			}

			if( (newleft - left) > dist && (newright - right) > dist )
				break;
		}
	} else {
		motor_set(-speed, -speed);
		while(true){
			int newleft = motor_get_left_encoder();
			int newright = motor_get_right_encoder();

			int read_diff = (newleft - left) - (newright - right);
			if(read_diff > 20 || read_diff < -20){ // rebalance drive outputs // negative means too much right // this might be wacked
				motor_set(-speed - read_diff / 4, -speed + read_diff / 4);
			}

			if( (newleft - left) < dist && (newright - right) < dist )
				break;
		}
	}
	motor_set(0, 0);
}

void drive_inches(float inches){
	drive_inches_speed(inches, DRIVE_MOTOR_FORWARD_SPEED);
}

void drive_inches_slow(float inches){
	drive_inches_speed(inches, DRIVE_MOTOR_PICKUP_SPEED);
}

void reverse_until_bumpers(){
	motor_set(-25, -25);

	//drive in reverse until bumper switches hit big bot
	while(! (bumperswitch_get_left() && bumperswitch_get_right()) ){
		if(bumperswitch_get_left())
			motor_set(-40, 0);
		if(bumperswitch_get_right())
			motor_set(0, -40);

		displayLCDNumber(0, 0, bumperswitch_get_left(), 6);
		displayLCDNumber(1, 0, bumperswitch_get_right(), 6);
	}

	motor_set(0, 0);
}

void rotate_degrees_right(float degrees){
	int left = motor_get_left_encoder();
	int right = motor_get_right_encoder();

	int dist = degrees_to_drive_encoder(degrees);

	motor_set(-DRIVE_MOTOR_TURN_SPEED, DRIVE_MOTOR_TURN_SPEED);

	//turn right a certain degree and then stop to release balls to big bot
	while (true){
		int newleft = motor_get_left_encoder();
		int newright = motor_get_right_encoder();

		if (((newleft - left) > dist) && ((newright - right) < (-dist)))
			break;
	}

	motor_set(0,0);
}

void rotate_degrees_left(float degrees){
	int left = motor_get_left_encoder();
	int right = motor_get_right_encoder();

	int dist = degrees_to_drive_encoder(degrees);

	motor_set(DRIVE_MOTOR_TURN_SPEED, -DRIVE_MOTOR_TURN_SPEED);

	//turn right a certain degree and then stop to release balls to big bot
	while (true){
		int newleft = motor_get_left_encoder();
		int newright = motor_get_right_encoder();

		if (((newleft - left) < -dist) && ((newright - right) > dist))
			break;
	}

	motor_set(0,0);
}


void dump_balls(){
	// turn on intake for a specified time
	intake_set(INTAKE_OUT_SPEED);
	top_intake_set(TOP_INTAKE_IN_SPEED); // we want the balls to go out the low, not the high

	time start = nSysTime;

	// push out all 4 balls for big bot to pull in
	while (nSysTime - start < DUMP_BALL_LOW_INTAKE_TIME)
		;

	//shut off intake
	intake_set(INTAKE_OFF_SPEED);
	top_intake_set(TOP_INTAKE_OFF_SPEED);
}

void pickup_balls(){
	drive_inches(3);
	wait1Msec(500);
	intake_set(INTAKE_IN_SPEED);
	wait1Msec(500);
	drive_inches_slow(8);
	wait1Msec(500);
	intake_set(INTAKE_OFF_SPEED);
	wait1Msec(500);
	drive_inches(-11);
}
