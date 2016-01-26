
/*

 Note:
    the channels 1-5 are on one breaker channel, 6-10 are on another

 Drive motor read in:
    i²C1 -> right drive
    i²C2 -> left drive

 Traverse motors (power expander)
    port 1  -> right
    port 10 -> left

 Feeder motors (power expander)
    port 2  -> right
    port 9  -> left

 Drive motors
    port 3 -> right 1
    port 4 -> right 2
    port 5 -> right 3
    port 6 -> left 1
    port 7 -> left 2
    port 8 -> left 3

 Analog battery power from power expander
    analog input port 1

*/




#pragma platform(VEX)

// Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous() {
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol() {

        /* This is the process of creating a job */
	testjob1_data duration = { .duration = 2000 };
	Command testjob1 = {
            .name = "testjob1",
            .starttime = nSysTime,
            .start = testjob1_start,
            .update = testjob1_update,
            .stop = testjob1_stop,
            .data = &duration,
            .freecmd = 0
        };
	jobhandler_startcommand(&testjob1);

	/* You shouldn't have to change anything below here */

	while (true) {
		jobhandler_tick();
	}
}
