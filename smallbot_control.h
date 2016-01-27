// speed defines for vairous subsystems/actions
const int SUCKER_OUT_SPEED = 75;
const int SUCKER_OFF_SPEED = 0;
const int SUCKER_IN_SPEED  = -50;

const int PUSHER_OUT_SPEED = 30;
const int PUSHER_OFF_SPEED = 0;
const int PUSHER_IN_SPEED  = -30;

void motor_set(int left, int right);

void intake_set(int speed);
void pusher_set(int speed);
