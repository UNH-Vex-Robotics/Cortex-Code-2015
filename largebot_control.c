int winch_get_encoder(){ return SensorValue(WinchEncoder); }

int winch_at_top(){ return SensorValue(WinchLimitSwitch); }


int smallbot_dist(){ return SensorValue(LiftSonar); }

int is_ball_ready(){
	return SensorValue(BallLightSensor) < BALL_EXISTS_THRESH;
}


void intake_set(int speed){
	motor[IntakeFunnel] = speed;
}

void belt_set(int speed){
	motor[Belt] = speed;
}

void shooter_motor_set(int speed){
	motor[FlyRight1] = speed;
	motor[FlyRight2] = speed;
	motor[FlyRight3] = speed;

	motor[FlyLeft1] = speed;
	motor[FlyLeft2] = speed;
	motor[FlyLeft3] = speed;
}

void winch_set(int speed){
	motor[LeftWinch]  = speed;
	motor[RightWinch] = speed;
}

int smallbot_lift_ready(){
	int dist = smallbot_dist()
	return dist > SMALLBOT_CORRECT_PLACEMENT_MIN &&
	       dist < SMALLBOT_CORRECT_PLACEMENT_MAX;
}
