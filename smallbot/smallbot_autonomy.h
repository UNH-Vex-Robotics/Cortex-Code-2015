// WARNING WARNING WARNING!!!!
// all of these functions are BLOCKING


const int DRIVE_MOTOR_FORWARD_SPEED = 40;
const int DRIVE_MOTOR_TURN_SPEED    = 40;
const int DRIVE_MOTOR_PICKUP_SPEED  = 25;

void drive_inches_speed(float inches, int speed); // can be negative
void drive_inches(float inches);
void drive_inches_slow(float inches);

void reverse_until_bumpers();

void rotate_degrees_right(float degrees);
void rotate_degrees_left(float degrees);
void rotate_degrees(float degrees);

void dump_balls_low();
void dump_balls_high();

void pickup_balls();
