// Relative encoder winch height:
// 2090 2050
// its about 360 from bottom engaged in lifting small bot

// relative is about 1850 - 1750 with no load

// There will be a speed difference w/ load vs w/out


const int WINCH_UP_SPEED   =  127;
const int WINCH_OFF_SPEED  =  0;
const int WINCH_DOWN_SPEED = -127;

void winch_set(int speed){
	motor(LeftWinch)  = speed;
	motor(RightWinch) = speed;
}

int winch_get_encoder(){ return SensorValue(WinchEncoder);}

int limit_switch_get(){ return SensorValue(WinchLimitSwitch);}

int small_bot_detector(){ return SensorValue(SmallBotDetector);}
