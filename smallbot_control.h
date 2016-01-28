// stuff for line sensor
typedef unsigned int linestate;
const int LINE_NONE   = 0;
const int LINE_RIGHT  = 1;
const int LINE_MIDDLE = 2;
const int LINE_LEFT   = 4;
const int LINE_LM     = 6;
const int LINE_RM     = 3;
const int LINE_LR     = 5;
const int LINE_LRM    = 7;

const unsigned int LINE_THRESH = 700;

// Max reading from the push plate encoders to be considered "Fully out"
const int PUSHER_ENC_DIST_MAX    = 983;
const int PUSHER_ENC_DIST_THRESH = 970;

// speed defines for vairous subsystems/actions
const int SUCKER_OUT_SPEED = 127;
const int SUCKER_OFF_SPEED = 0;
const int SUCKER_IN_SPEED  = -127;

const int PUSHER_OUT_SPEED = 127;
const int PUSHER_OFF_SPEED = 0;
const int PUSHER_IN_SPEED  = -127;

// Various robotly functions

void motor_set(int left, int right);

void intake_set(int speed);
void pusher_set(int speed);

int motor_get_left_encoder();
int motor_get_right_encoder();

int pusher_get_left_encoder();
int pusher_get_right_encoder();
int pusher_get_home_switch();

int bumperswitch_get_left();
int bumperswitch_get_right();
