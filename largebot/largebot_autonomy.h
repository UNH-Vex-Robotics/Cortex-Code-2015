// #include "largebot_control.h"

// These time are in milliseconds (i think)
const time SHOOTER_OUT_TIMESPAN = 200;
const time SHOOTER_CYCLE_SPEED  = 400;

typedef struct {
	int enabled;
	time last_shot;
	int pneustate;
} AutoShooter;

int auto_shoot();
