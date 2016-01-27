
jobstatus emptyballs_start(Command *cmd);
jobstatus emptyballs_update(Command *cmd);
jobstatus emptyballs_stop(Command *cmd);

typedef unsigned int State;

const State EB_START     = 0;
const State EB_PLATE_OUT = 1; // plate going out
const State EB_PLATE_IN  = 2; // plate going in

typedef struct {
    State state;
} emptyballs_data;
