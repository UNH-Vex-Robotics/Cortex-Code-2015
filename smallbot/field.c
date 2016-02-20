// this assumes that it is 100% ok to go in a direct line from the current location to the target point
void go_to_point(float x, float y){
	// determine angle to go at
	// determine distance to go
	// go!

	Point start = currentPoint;

	Point diff;
	diff.x = p.x - start.x;
	diff.y = p.y - start.y;

	float dist = sqrt(diff.x * diff.x + diff.y * diff.y);

	if(dist < 0.05) return;

	float deltaheading;
	if(abs(diff.x) <= 0.5){
		deltaheading = 90;
	} else {
		deltaheading = acos(diff.x/dist) * 180 / PI;
	}

	if(diff.y < 0)
		deltaheading = -deltaheading;

	float curheading = get_gyro_degrees();

	rotate_degrees(deltaheading);

	drive_inches(dist);
}

// this assumes that it is 100% ok to go in a direct line from the current location to the target point
void get_balls_at_point(float x, float y){
	// determine angle to go at
	// determine distance to go (aka just short of the balls)
	// go!

	float dx = x - currentx;
	float dy = y - currenty;

	float heading = heading_to_dxdy(x, y);

	float dist = dist_to_dxdy(x, y);
	
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

void heading_to_dxdy(float dx, float dy){
	// dist here should always be greater than the radious of the robot
	float dist = dist_to_dxdy(dx, dy);

	float heading;
	if(abs(dx) = 0.0){
		heading = 90;
	} else {
		heading = acos(dx/dist) * 180 / PI;
	}

	if(dy < 0)
		heading = -heading;

	return heading;
}

void dist_to_dxdy(float dx, float dy){
	return sqrt(dx * dx + dy * dy);
}
