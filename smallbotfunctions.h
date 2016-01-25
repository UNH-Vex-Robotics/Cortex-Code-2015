// speed defines for vairous subsystems/actions
const int SUCKER_OUT_SPEED ;
const int SUCKER_OFF_SPEED ;
const int SUCKER_IN_SPEED ;

const int PUSHER_OUT_SPEED ;
const int PUSHER_OFF_SPEED ;
const int PUSHER_IN_SPEED ;

// Functions for setting output values //
void setmotors_forward(int speed){ move(speed, speed); }
void setmotors_backward(int speed){ move(-speed, -speed); } // check this; it may be [0,256)

void setmotors(int left, int right);

void sucker_set(int speed);
void pusher_set(int speed);

// Functions for doing things through the dimmension of time //

void pusher_pushballsout(){
    sucker_set(SUCKER_OUT_SPEED);
    pusher_set(PUSHER_OUT_SPEED);
    wait
    pusher_set(PUSHER_IN_SPEED);
    wait for limit
    pusher_set(PUSHER_OFF_SPEED);
}

void move_forward(int distance);

bool pusher_isin();
