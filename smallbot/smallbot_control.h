typedef int time;

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

// miliseconds it takes to dump all balls out
const int DUMP_BALL_LOW_INTAKE_TIME  = 1500;
const int DUMP_BALL_HIGH_INTAKE_TIME = 1500;

// speed defines for vairous subsystems/actions
const int INTAKE_IN_SPEED  = 40;
const int INTAKE_OFF_SPEED = 0;
const int INTAKE_OUT_SPEED = -40;

const int TOP_INTAKE_OUT_SPEED = 127;
const int TOP_INTAKE_OFF_SPEED = 0;
const int TOP_INTAKE_IN_SPEED  = -127;

const int DRIVE_WHEEL_CIRC = 10.375; //in inches

const int GYRO_TICKS_PER_DEGREE = 10;

// Various robotly functions
void motor_set(int right, int left);
void arcade_drive(int x, int y);

int motor_get_left_encoder();
int motor_get_right_encoder();

float drive_encoder_to_inches(int encoder_value);
int   inches_to_drive_encoder(float inches);
float drive_encoder_to_degrees(int encoder_value);
int   degrees_to_drive_encoder(float degrees_value);


void intake_set(int speed);
void top_intake_set(int speed);

int   get_gyro();
float get_gyro_degrees();
int   gyro_degrees_to_ticks(float deg);
float gyro_ticks_to_degrees(int ticks);

int bumperswitch_get_left();
int bumperswitch_get_right();
