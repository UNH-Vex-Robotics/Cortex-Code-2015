void field_setup(){
	// robot dimmension is 14 wide by 15 long
	currentPoint.x = 7.5;
	currentPoint.y = 36;

	Point p = test();
}


// this assumes that it is 100% ok to go in a direct line from the current location to the target point
void goToPoint(Point p){
	// determine angle to go at
	// determine distance to go
	// go!

	Point start = currentPoint;

	Point diff;
	diff.x = p.x - start.x;
	diff.y = p.y - start.y;

	float dist = sqrt(diff.x * diff.x + diff.y * diff.y);

	if(abs(dist) < 0.05) return;

	float deltaheading;
	if(abs(diff.x) <= 0.5){
		deltaheading = 90;
	} else {
		deltaheading = acos(diff.x/dist) * 180 / PI;
	}

	if(diff.y < 0)
		deltaheading = -deltaheading;

	float curheading = get_gyro();

	rotate_degrees(deltaheading);
}

void setCurrentPoint(Point p){
	currentPoint = p;
}
