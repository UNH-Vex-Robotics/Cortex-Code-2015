// #include "largebot_autonomy.h"

AutoShooter autoshootdata = {
	0, 0, 0
};

int would_auto_shoot();

// return true if shot
// Call in a loop
// This extends and retracts the piston
int auto_shoot(){
	if(autoshootdata.pneustate){
		if(nSysTime - autoshootdata.last_shot > SHOOTER_OUT_TIMESPAN){
			set_pneumatics(SHOOTER_IN);
			autoshootdata.pneustate = false;
			intake_set(INTAKE_SPEED);
			belt_set(BELT_SPEED);
		}
	} else if(would_auto_shoot()){
		intake_set(INTAKE_OFF_SPEED);
		belt_set(BELT_OFF_SPEED);
		autoshootdata.last_shot = nSysTime;
		set_pneumatics(SHOOTER_OUT);
		autoshootdata.pneustate = true;
		return 1;
	}
	return 0;
}

// this checks if there is a ball,
// then if there has been enough time since the previous ball has been shot
int would_auto_shoot(){
	if(!is_ball_ready()) return 0;
	time now = nSysTime;
	if(now - SHOOTER_CYCLE_SPEED < autoshootdata.last_shot) return 0;
	return 1;
}
