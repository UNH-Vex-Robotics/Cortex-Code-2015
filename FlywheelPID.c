
task FlywheelPID()
{
	velocity = //encoder value translated to rad/s//
	float kp = 0.0;
	float ki = 0.0;
	float kd = 0.0;

	float current_error = 0;
	float circ = 5*PI;

	float i_control_active = ((1*12/circ)*360); //1ft per sec//

	float errorT;
	float prev_error;
	float proportion;
	float integral;
	float derivative;

	while(true)
	{
		float error	= ((power*12/circ)*360) - velocity //target value - current motor speed//

		if(error<i_control_active && error != 0)
			errorT += error;
		else
			errorT = 0;

		if(errorT > 50/ki)
			errorT = 50/ki;

		if(error == 0)
			derivative = 0;

		proportion = error*kp;
		integral = errorT*ki;
		derivative = (error - prev_error)*kd;

		prev_error = error;


		current = proportion + integral + derivative; //motor value to be set//

		if(power == 0)
			current = 0;

		if(current < 0)
			current = 0

		motor[portz] = current;
	}


}
