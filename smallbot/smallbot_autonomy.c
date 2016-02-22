//#include "smallbot_autonomy.h"

void drive_inches_speed(float inches, int speed){
	int left = motor_get_left_encoder();
	int right = motor_get_right_encoder();

	int forward = (inches > 0.0);

	int dist = inches_to_drive_encoder(inches);

	float startDeg = gyro_get_degrees();

	// esitmated travel:
	//  x dist * cosDegrees(startDeg),
	//  y dist * sinDegrees(startDeg),

	// gyro go-straight
	if(forward){
		motor_set(speed, speed);
		while(true){
			int newleft = motor_get_left_encoder();
			int newright = motor_get_right_encoder();

			float diff = gyro_get_degrees() - startDeg;
			// if difference in heading positive, add more to right
			motor_set(speed + diff / 5.0, speed - diff / 5.0);

			if( (newleft - left) > dist && (newright - right) > dist )
				break;
		}
	} else {
		motor_set(-speed, -speed);
		while(true){
			float diff = gyro_get_degrees() - startDeg;
			// if difference in heading positive, add more to left
			motor_set(-speed - diff / 5.0, -speed + diff / 5.0);

			if( (motor_get_left_encoder() - left) > dist && (motor_get_right_encoder() - right) > dist )
				break;
		}
	}

	motor_set(0, 0);
	return;

	// encoder go-straight
	if(forward){
		motor_set(speed, speed);
		while(true){
			int newleft = motor_get_left_encoder();
			int newright = motor_get_right_encoder();

			int read_diff = (newleft - left) - (newright - right);
			if(read_diff > 5 || read_diff < -5){ // rebalance drive outputs // negative means too much right
				motor_set(speed + read_diff / 5, speed - read_diff / 5);
			}

			if( (motor_get_left_encoder() - left) < dist && (motor_get_right_encoder() - right) < dist )
				break;
		}
	} else {
		motor_set(-speed, -speed);
		while(true){
			int newleft = motor_get_left_encoder();
			int newright = motor_get_right_encoder();

			int read_diff = (newleft - left) - (newright - right);
			if(read_diff > 5 || read_diff < -5){ // rebalance drive outputs // negative means too much right // this might be wacked
				motor_set(-speed - read_diff / 4, -speed + read_diff / 4);
			}

			if( (newleft - left) < dist && (newright - right) < dist )
				break;
		}
	}
	motor_set(0, 0);
}

void drive_to_dxdy2(float dx, float dy){
	float startDist = dist_to_dxdy(dx, dy);

	float targetx = currentx + dx;
	float targety = currenty + dy;

	// int dist = inches_to_drive_encoder(startDist);

	float startHeading = get_gyro_degrees();
	float neededHeading = heading_to_dxdy(dx, dy);

	face_heading(neededHeading);

	float startHeading2 = get_gyro_degrees();

	string a;
	sprintf(a, "s1 %3.1 s2 %3.1", startHeading, startHeading2);
	displayLCDString(0, 0, a);

	wait1Msec(1000);

	int speed = 20;

	int lastleft = motor_get_left_encoder();
	int lastright = motor_get_right_encoder();

	motor_set(speed, speed);

	while(abs(targetx - currentx) > 2.0 && abs(targety - currenty) > 2.0){
		int newleft = motor_get_left_encoder();
		int newright = motor_get_right_encoder();


	}
}

void drive_to_dxdy(float dx, float dy){
	int dist = inches_to_drive_encoder(dist_to_dxdy(dx, dy));

	float startDeg = gyro_get_degrees();

	float heading = heading_to_dxdy(dx, dy);
	string str;
	sprintf(str, "head %3.2f", heading);
	displayLCDString(0, 0, str);

	face_heading(heading);
	sprintf(str, "done");
	displayLCDString(0, 0, str);

	int speed = 30; // start off at 50; gets smaller when closer to target

	float totaldx = 0, totaldy = 0;

	int lastleft = motor_get_left_encoder();
	int lastright = motor_get_right_encoder();
	float lastheading = heading;
	float lastdist = dist_to_dxdy(dx, dy);

	motor_set(speed, speed);

	while(lastdist > .5){
		int newleft = motor_get_left_encoder();
		int newright = motor_get_right_encoder();

		string str2;
		sprintf(str2, "lh %3.1f d %3.2f", lastheading, lastdist);
		displayLCDString(1, 0, str2);

		float newheading = ((float)SensorValue[ChassisGyro]) / 10.0;
		//float newheading = gyro_get_degrees();

		int aveEnc = (newleft - lastleft + newright - lastright) / 2;

		float distt = drive_encoder_to_inches(aveEnc);

		float dyinch = distt * sinDegrees((lastheading + newheading) / 2.0);
		float dxinch = distt * cosDegrees((lastheading + newheading) / 2.0);

		totaldx += dxinch;
		totaldy += dyinch;

		float newtargetheading = heading_to_dxdy(dx - totaldx, dy - totaldy);
		float newdist = dist_to_dxdy(dx - totaldx, dy - totaldy);

		float speeddiff = (newtargetheading - newheading);
		if(speeddiff < -180.0) speeddiff += 360.0;
		if(speeddiff >  180.0) speeddiff -= 360.0;

		string str3;
		// sprintf(str3, "n %3.1f n %3.1f", newheading, newtargetheading);
		// sprintf(str3, "nh %3.2f s %3.2f", newheading, sinDegrees(newheading));
		// sprintf(str3, "d %3.2f y %3.2f", distt, dxinch);
		// sprintf(str3, "t %3.2f s %3.2f", totaldx, dxinch);
		// sprintf(str3, "nd %3.2f d %3.2f", newdist, dist);
		// sprintf(str3, "x %3.2f y %3.2f", dxinch, dyinch);
		// sprintf(str3, "s %3.2f t %3.2f", speeddiff, newdist);
		// sprintf(str3, "s %3d t %3.2f", aveEnc, distt);
		sprintf(str3, "th %3.1f sd %3.1f", newtargetheading, speeddiff);
		displayLCDString(0, 0, str3);

		if(newdist < 8.0) speed = 25; // if closer, go slower

		speeddiff *= 0.15;

		motor_set(speed + speeddiff, speed - speeddiff);

		lastdist = newdist;
		lastheading = newheading;

		lastleft = newleft;
		lastright = newright;

		wait1Msec(25); // bigger numbers will result in a larger 'averaging effect'
		//motor_set(0, 0);
		//wait1Msec(10000);
	}

	motor_set(0, 0);

	currentx += totaldx;
	currenty += totaldy;

	return;

	// esitmated travel:
	//  x = inches * cosDegrees(startDeg),
	//  y = inches * sinDegrees(startDeg),
}

void drive_inches(float inches){
	drive_inches_speed(inches, DRIVE_MOTOR_FORWARD_SPEED);
}

void drive_inches_slow(float inches){
	drive_inches_speed(inches, DRIVE_MOTOR_PICKUP_SPEED);
}

void reverse_until_bumpers(){
	motor_set(-34, -34);

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

// this tries to keep the amount rotated by each side equal


void rotate_degrees_right(float degrees){
	int leftstart  = motor_get_left_encoder();  // left will be increasing
	int rightstart = motor_get_right_encoder(); // right will be decreasing

	int left = 0, right = 0;
	int dist = degrees_to_drive_encoder(degrees);

	motor_set(-DRIVE_MOTOR_TURN_SPEED, DRIVE_MOTOR_TURN_SPEED);

	SensorValue[ChassisGyro] = 0;

	//turn right a certain degree and then stop to release balls to big bot
	while (true){
		int newleft  = motor_get_left_encoder();
		int newright = motor_get_right_encoder();

		left += newleft - leftstart;
		right += newright - rightstart;

		int diff = left + right; // ideally should be zero
		diff *= .05;
		motor_set(-DRIVE_MOTOR_TURN_SPEED+diff, DRIVE_MOTOR_TURN_SPEED+diff);

		if (((newleft - leftstart) > dist) && ((newright - rightstart) < (-dist)))
			break;
		//if(get_gyro_degrees() < -degrees)
		//	break;

		displayLCDNumber(1, 0, diff, 5);
		wait1Msec(25);
	}

	motor_set(0, 0);
}

// this tries to keep the amount rotated by each side equal
void rotate_degrees_left(float degrees){
	int leftstart = motor_get_left_encoder();
	int rightstart = motor_get_right_encoder();

	int left = 0, right = 0;
	int dist = degrees_to_drive_encoder(degrees);

	motor_set(DRIVE_MOTOR_TURN_SPEED, -DRIVE_MOTOR_TURN_SPEED);

	SensorValue[ChassisGyro] = 0;

	//turn right a certain degree and then stop to release balls to big bot
	while (true){
		int newleft = motor_get_left_encoder();
		int newright = motor_get_right_encoder();

		left += newleft - leftstart;
		right += newright - rightstart;

		int diff = right + left;
		diff *= .05;
		motor_set(DRIVE_MOTOR_TURN_SPEED-diff, -DRIVE_MOTOR_TURN_SPEED-diff);

		if (((newleft - leftstart) < -dist) && ((newright - rightstart) > dist))
			break;
		if(get_gyro_degrees() > degrees)
			break;

		wait1Msec(25);
	}

	motor_set(0,0);
}

// LEFT/COUNTER-CLOCKWISE IS POSITIVE
void rotate_degrees(float degrees){
	while(degrees > 180.0){ degrees -= 360; }
	while(degrees < -180.0){ degrees += 360; }
	if(degrees < 0) rotate_degrees_right(-degrees);
	else            rotate_degrees_left(degrees);
}


void dump_balls_low(){
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

void dump_balls_high(){
	// turn on intake for a specified time
	intake_set(INTAKE_IN_SPEED);
	top_intake_set(TOP_INTAKE_OUT_SPEED); // we want the balls to go out the low, not the high

	time start = nSysTime;

	// push out all 4 balls for big bot to pull in
	while (nSysTime - start < DUMP_BALL_HIGH_INTAKE_TIME)
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
