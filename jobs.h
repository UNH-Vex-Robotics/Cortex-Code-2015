
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
    int freecmd;
} Command;

const jobstatus JOB_NORMAL = 1;
const jobstatus JOB_DONE   = 2;

void jobhandler_tick();
void jobhandler_startcommand(Command *c);
void jobhandler_killall();
