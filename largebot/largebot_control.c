int winch_get_encoder(){ return SensorValue(WinchEncoder); }

int winch_at_top(){ return SensorValue(WinchRaised); }


int smallbot_dist(){ return SensorValue(LiftSonar); }

int is_ball_ready(){
	return SensorValue(BallSensor) < BALL_EXISTS_THRESH;
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
	motor[WinchLeft]  = speed;
	motor[WinchRight] = speed;
}

int smallbot_lift_ready(){
	int dist = smallbot_dist();
	return dist > SMALLBOT_CORRECT_PLACEMENT_MIN &&
	       dist < SMALLBOT_CORRECT_PLACEMENT_MAX;
}

void set_pneumatics(int state){
	SensorValue(Shooter) = !!state;
}

void winch_down_up()
{
	while( winch_get_encoder()< MAX_WINCH_LENGTH )
	{
		winch_set(WINCH_DOWN_SPEED);
	}
	while( winch_at_top()== 0 )
	{
		winch_set(WINCH_UP_SPEED);
	}
}

int shooter_motor_speed()
	{
		return ((SensorValue(I2C_1) + SensorValue(I2C_2) + SensorValue(I2C_3) + SensorValue(I2C_4) + SensorValue(I2C_5) + SensorValue(I2C_6))/6);
	}
