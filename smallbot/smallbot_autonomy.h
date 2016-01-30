// WARNING WARNING WARNING!!!!
// all of these functions are BLOCKING


const int DRIVE_MOTOR_FORWARD_SPEED = 40;
const int DRIVE_MOTOR_TURN_SPEED    = 40;
const int DRIVE_MOTOR_PICKUP_SPEED  = 10;

void drive_inches_speed(float inches, int speed); // can be negative
void drive_inches(float inches){ drive_inches_speed(inches, DRIVE_MOTOR_FORWARD_SPEED); }
void drive_inches_slow(float inches){ drive_inches_speed(inches, DRIVE_MOTOR_PICKUP_SPEED); }

void drive_until_bumpers();

void rotate_degrees_right(float degrees);
void rotate_degrees_left(float degrees); // NYI

void dump_balls();

void pickup_balls();
