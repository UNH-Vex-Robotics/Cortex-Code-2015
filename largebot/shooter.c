typedef struct {
	int target_speed;
	int raise_button_pressed;
	int lower_button_pressed;
} ShooterData;

void shooter_set_target_speed(int speed){
	target_speed = speed;
}

int shooter_get_target_speed(){
	return target_speed;
}

void shooter_increment_speed(int button){
	if(button){
		if(!shooter_data.raise_button_pressed){
			shooter_data.raise_button_pressed = true;
			target_speed++;
			shooter_set(target_speed);
		}
	} else {
		shooter_data.raise_button_pressed = false;
	}
}

void shooter_decrement_speed(int button){
	if(button){
		if(!shooter_data.lower_button_pressed){
			shooter_data.lower_button_pressed = true;
			target_speed--;
			shooter_set(target_speed);
		}
	} else {
		shooter_data.lower_button_pressed = false;
	}
}

