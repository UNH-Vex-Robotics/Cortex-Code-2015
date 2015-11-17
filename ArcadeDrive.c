#pragma config(Motor,  port1,           RearDriver,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port8,           RearPassanger, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           FrontPassanger, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          FrontDriver,   tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)
	{
		//Forward and Backward movement "RIGHT joystick" VERTICAL
		short front = - vexRT[Ch2];
		short turn = - vexRT[Ch1];

		//-----------------------------------------------------------------------------------------------------------------------

		motor[FrontDriver] = front - turn;
	  	motor[RearDriver] = front - turn;
		motor[FrontPassanger] = front + turn;
		motor[RearPassanger] = front + turn;

	}
}
