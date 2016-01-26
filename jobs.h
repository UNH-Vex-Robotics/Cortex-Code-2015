
typedef int jobstatus;
typedef int commandstatus;
typedef unsigned long time;

typedef struct {
    char *name;
    time starttime;
    jobstatus (*start)(Command *);
    jobstatus (*update)(Command *);
    jobstatus (*stop)(Command *);
    void *data;
    commandstatus status;
} Command;

const jobstatus JOB_NORMAL          = 1;
const jobstatus JOB_DONE            = 2;
const jobstatus JOB_CLEANUP_COMMAND = 4;

const commandstatus COMMAND_RUNNING       = 1;
const commandstatus COMMAND_STOPPED       = 2;
const commandstatus COMMAND_WAITING_INPUT = 4;
const commandstatus COMMAND_WAITING_TIME  = 8;

void jobhandler_tick();
void jobhandler_startcommand(Command *c);
