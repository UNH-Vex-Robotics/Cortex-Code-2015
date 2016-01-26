#include "jobs.h"
#include "testjob1.h"
#include "control.h"


/* This is a test job to run the robot forward for a couple seconds */


// This function will be run once, when the command is started
jobstatus testjob1_start(Command *cmd){
    // Start motors moving
    motors_set(80, 80);
    return JOB_NORMAL;
}

// This function will be run over and over, keep it short and NON-BLOCKING
jobstatus testjob1_update(Command *cmd){
    // check if the time elapsed is long enough
    testjob1_data *data = cmd->data;
    if(data->duration > cmd->start - nSysTime)
        return JOB_DONE;
    return JOB_NORMAL;
}

// This function will be run once, when the command is over.
// This is where all cleanup should be done (ie turning off outputs)
jobstatus testjob1_stop(Command *cmd){
    motors_set(0, 0);
    return JOB_CLEANUP_COMMAND;
}
