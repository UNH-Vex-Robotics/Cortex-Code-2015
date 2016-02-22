// this assumes that it is 100% ok to go in a direct line from the current location to the target point
void go_to_point(float x, float y){
	float dx = x - currentx;
	float dy = y - currenty;

	float heading = heading_to_dxdy(dx, dy);

	float dist = dist_to_dxdy(dx, dy);

	float godx = (dist - 8) * cosDegrees(heading);
	float gody = (dist - 8) * sinDegrees(heading);

	drive_to_dxdy(godx, gody);
	face_heading(heading); // just to make sure...

}

// this assumes that it is 100% ok to go in a direct line from the current location to the target point
void get_balls_at_point(float x, float y){
	// determine angle to go at
	// determine distance to go (aka just short of the balls)
	// go!

	float dx = x - currentx;
	float dy = y - currenty;

	float heading = heading_to_dxdy(dx, dy);

	float dist = dist_to_dxdy(dx, dy);

	float godx = (dist - 8) * cosDegrees(heading);
	float gody = (dist - 8) * sinDegrees(heading);

	drive_to_dxdy(godx, gody);
	face_heading(heading); // just to make sure...

	pickup_balls(); // this moves us forward, and back.
}

// note heading values are defined in field.h
void face_heading(float heading){
	float cur = get_gyro_degrees();
	float turn = heading - cur;
	rotate_degrees(turn);
}

float heading_to_dxdy(float dx, float dy){
	// dist here should always be greater than the radious of the robot
	float dist = dist_to_dxdy(dx, dy);

	float heading;
	if(abs(dx) == 0.0){
		heading = 90.0;
	} else {
		heading = acos(dx/dist) * 180.0 / PI;
	}

	if(dy < 0.0)
		heading = -heading;

	return heading;
}

float dist_to_dxdy(float dx, float dy){
	return sqrt(dx * dx + dy * dy);
}
