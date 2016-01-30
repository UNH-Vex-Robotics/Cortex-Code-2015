void drive_inches_speed(float inches, int speed){
	int left = motor_get_left_encoder();
	int right = motor_get_right_encoder();

	int forward = inches < 0;

	if(forward){
		motor_set(speed, speed);
	} else {
		motor_set(-speed, -speed);
	}

	int dist = inches_to_drive_encoder(inches);

	// move forward a set distance and then stop
	while (true){
		int newleft = motor_get_left_encoder();
		int newright = motor_get_right_encoder();

		if(forward)
			if (((newleft - left) > dist) && ((newright - right) > dist))
				break;
		else
			if (((newleft - left) < dist) && ((newright - right) < dist))
				break;
	}

	motor_set(0,0);
}

void drive_inches(float inches){
	drive_inches_speed(inches, DRIVE_MOTOR_FORWARD_SPEED);
}

void drive_inches_slow(float inches){
	drive_inches_speed(inches, DRIVE_MOTOR_PICKUP_SPEED);
}

void reverse_until_bumpers(){
	motor_set(-10, -10);

	//drive in reverse until bumper switches hit big bot
	while(! (bumperswitch_get_left() && bumperswitch_get_right()) ){
		if(bumperswitch_get_left())
			motor_set(-10, 0);
		if(bumperswitch_get_right())
			motor_set(0, -10);
	}

	motor_set(0, 0);
}

void rotate_degrees_right(float degrees){
	int left = motor_get_left_encoder();
	int right = motor_get_right_encoder();

	int dist = degrees_to_drive_encoder(degrees);

	motor_set(DRIVE_MOTOR_TURN_SPEED, -DRIVE_MOTOR_TURN_SPEED);

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

	motor_set(-DRIVE_MOTOR_TURN_SPEED, DRIVE_MOTOR_TURN_SPEED);

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
	int left = pusher_get_left_encoder();
	int right = pusher_get_right_encoder();

	// turn on pusher and intake
	intake_set(INTAKE_OUT_SPEED);
	pusher_set(PUSHER_OUT_SPEED / 2);

	// push out all 4 balls for big bot to pull in
	while (true){
		int newleft = pusher_get_left_encoder();
		int newright = pusher_get_right_encoder();

		if (((newleft - left) > PUSHER_ENC_DIST_THRESH) && ((newright - right) < (-PUSHER_ENC_DIST_THRESH)))
			break;
	}

	//shut off intake
	//reverse pusher to initial position
	intake_set(INTAKE_OFF_SPEED);
	pusher_set(PUSHER_IN_SPEED / 2);

	while(!pusher_get_home_switch()){}

	pusher_set(PUSHER_OFF_SPEED);
}

void pickup_balls(){
	drive_inches(3.0);
	intake_set(INTAKE_IN_SPEED);
	drive_inches_slow(4.0);
	intake_set(INTAKE_OFF_SPEED);
	drive_inches(-7.0);
}
