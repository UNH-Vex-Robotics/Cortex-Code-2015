
void winch_set(int speed){
	motor(LeftWinch)  = speed;
	motor(RightWinch) = speed;
}

int winch_get_encoder(){ return SensorValue(WinchEncoder);}

int limit_switch_get(){ return SensorValue(WinchLimitSwitch);}

int small_bot_detector(){ return SensorValue(SmallBotDetector);}
