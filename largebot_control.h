// Relative encoder winch height:
// 2090 2050
// its about 360 from bottom engaged in lifting small bot

// relative is about 1850 - 1750 with no load

// There will be a speed difference w/ load vs w/out


const int WINCH_UP_SPEED   =  127;
const int WINCH_OFF_SPEED  =  0;
const int WINCH_DOWN_SPEED = -127;

const int SHOOTER_SPEED = 90;
const int SHOOTER_OFF_SPEED = 90;

// if the ball-detecting light sensor reads below this value, we consider it a ball
const int BALL_EXISTS_TRESH = 400;

// CALIBRATEME
const int SMALLBOT_CORRECT_PLACEMENT_MIN = 0;
const int SMALLBOT_CORRECT_PLACEMENT_MAX = 0;

const int SHOOTER_OUT = 1;
const int SHOOTER_IN  = 0;

void winch_set(int speed);
int winch_get_encoder();
int winch_at_top();

int smallbot_lift_ready();
int smallbot_dist();

int is_ball_ready();

void intake_set(int speed);
void belt_set(int speed);

void shooter_motor_set(int speed);

void setpneumatics(int state);
