// #include "largebot_autonomy.h"

AutoShooter autoshootdata = {
	0, 0, 0
};

// return true if shot
// Call in a loop
// This extends and retracts the piston
int auto_shoot(){
	if(autoshootdata.pneustate){
		if(nSysTime - autoshootdata.last_shot > SHOOTER_OUT_TIMESPAN){
			set_pneumatics(SHOOTER_IN);
			autoshootdata.pneustate = false;
		}
	} else if(would_auto_shoot()){
		autoshootdata.last_shot = nSysTime;
		set_pneumatics(SHOOTER_OUT);
		autoshootdata.pneustate = true;
	}
}

time auto_last_shot(){
    return autoshootdata.last_shot;
}

// this checks if there is a ball,
// then if there has been enough time since the previous ball has been shot
int would_auto_shoot(){
	if(!is_ball_ready()) return 0;
	time now = nSysTime;
	if(now - SHOT_DELAY < autoshootdata.last_shot) return 0;
	if(now - SHOT_DELAY < autoshootdata.last_shot) return 0;
}
