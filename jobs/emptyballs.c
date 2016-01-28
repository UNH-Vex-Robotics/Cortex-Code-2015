// #include "jobs.h"
// #include "emptyballs.h"
// #include "control.h"


/* This job empties all balls in the bot */


// This function will be run once, when the command is started
jobstatus emptyballs_start(Command *cmd){
    // Start motors moving
    intake_set(INTAKE_OUT_SPEED);
    pusher_set(PUSHER_OUT_SPEED);
    cmd->data->state = EB_PLATE_OUT;
    return JOB_NORMAL;
}

// This function will be run over and over, keep it short and NON-BLOCKING
jobstatus emptyballs_update(Command *cmd){
    // check state, check input, possibly change state
    emptyballs_data *data = cmd->data;
    if(data->state == EB_PLATE_OUT){
        int l = pusher_get_left_encoder();
        int r = pusher_get_right_encoder();
        if(l < -PUSHER_ENC_DIST_THRESH &&
           r >  PUSHER_ENC_DIST_THRESH){
            intake_set(INTAKE_IN_SPEED);
            pusher_set(PUSHER_IN_SPEED);
            data->state = EB_PLATE_IN;
        }
    } else if( data->state == EB_PLATE_IN &&
               pusher_get_home_switch() ){
        return JOB_DONE;
    }
    return JOB_NORMAL;
}

// This function will be run once, when the command is over.
// This is where all cleanup should be done (ie turning off outputs)
jobstatus emptyballs_stop(Command *cmd){
    intake_set(INTAKE_OFF_SPEED);
    pusher_set(PUSHER_OFF_SPEED);
    return JOB_CLEANUP_COMMAND;
}
