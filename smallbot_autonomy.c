
void drive_inches(float inches){
	int left = motor_get_left_encoder();
	int right = motor_get_right_encoder();

	int forward = inches < 0;

	if(forward){
		motor_set(DRIVE_MOTOR_FORWARD_SPEED, DRIVE_MOTOR_FORWARD_SPEED);
	} else {
		motor_set(-DRIVE_MOTOR_FORWARD_SPEED, -DRIVE_MOTOR_FORWARD_SPEED);
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

void drive_until_bumpers(){
	motors_set(-10, -10);

	//drive in reverse until bumper switches hit big bot
	while(! (bumperswitch_get_left() && bumperswitch_get_right()) )
		;

        motors_set(0, 0);
}

void rotate_degrees_right(float degrees){
	left = motor_get_left_encoder();
	right = motor_get_right_encoder();

	dist = degrees_to_drive_encoder(degrees);

	motor_set(100,-100);

	//turn right a certain degree and then stop to release balls to big bot
	while (true){
		int newleft = motor_get_left_encoder();
		int newright = motor_get_right_encoder();

		if (((newleft - left) > dist) && ((newright - right) < (-dist)))
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
	drive_inches(3);
	intake_set(INTAKE_IN_SPEED);
	drive_inches_slow(4);
	intake_set(INTAKE_OFF_SPEED);
	drive_inches(-7);
}
