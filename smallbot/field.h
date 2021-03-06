
/*

->  means smallbot start point

       ___________________________________________
   ^   |      :      :      :      :      :      |
 y |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
 a |   |      :      :      :      :      :      |
 x |   |      :      :      :      :      :      |
 i |   |______:______:______:______:______:______|
 s |   |      :      :      :      :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |   |      :      :      :      :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |   |      :      :      :      :      :      |
   |   |   -> :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |   |      :      :      :      :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |(0, 0)
   +----------------------------------> x axis

// HEADING:
//
//          90
//          ^
//          |
//          |
// 180 <----+----> 0
//          |
//          |
//          v
//          -90


       ___________________________________________
   ^   |            /:      :      :\            |
 y |   |         //  :      :      :  \\         |
   |   |       /_____:______:______:_____\       |
 a |   |     /:      :      :      :      :\     |
 x |   |  //  :      :      :      :      :  \\  |
 i |   |/_____:______:______:______:______:_____\|
 s |   |      :      :      :      :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |   |      :      :      :      :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |   |      :      :      :      :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |   |      :      :      :      :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:______:______:______:______|
   |
   +----------------------------------> x axis


// Lines
       ___________________________________________
   ^   |            /               \            |
 y |   |         //  :      :      :  \\         |
   |   |       / __     __     __     __ \       |
 a |   |     / \                         / \     |
 x |   |  //  :  \\  :      :      :  //  :  \\  |
 i |   |/ __     __ \   __     __   / __     __ \|
 s |   |              \           /              |
   |   |      :      :  \\  :  //  :      :      |
   |   |  __     __     __ \ / __     __     __  |
   |   |                   / \                   |
   |   |      :      :  //  :  \\  :      :      |
   |   |_____________ / __     __ \ ______ ______|
   |   |             |             |             |
   |   |      :      |      :      |      :      |
   |   |  __     __  |  __     __  |  __     __  |
   |   |             |             |             |
   |   |      :      |      :      |      :      |
   |   |_____________|_____________|______ ______|
   |
   +----------------------------------> x axis

// 10 stacks of balls
       ___________________________________________
   ^   |            /:     XXX     :\            |
 y |   |         //  :      :      :  \\         |
   |   |       /_____:_____XXX_____:_____\       |
 a |   |     /:      :     XXX     :      :\     |
 x |   |  //  :      :      :      :      :  \\  |
 i |   |/_____:_____XXX_____:_____XXX_____:_____\|
 s |   |      :     XXX     :     XXX     :      |
   |   |      :      :      :      :      :      |
   |   |X_____:______:______:______:______:_____X|
   |   |X     :      :      :      :      :     X|
   |   |      :      :      :      :      :      |
   |   |______:_____XXX_____:_____XXX_____:______|
   |   |      :     XXX     :     XXX     :      |
   |   |      :      :      :      :      :      |
   |   |______:______:_____XXX_____:______:______|
   |   |      :      :     XXX     :      :      |
   |   |      :      :      :      :      :      |
   |   |______:______:_____XXX_____:______:______|
   |
   +----------------------------------> x axis

// (  0,  72)
// ( 48,  48)
// ( 48,  96)
// ( 72,   0)
// ( 72,  24)
// ( 72, 120)
// ( 72, 144)
// ( 96,  48)
// ( 96,  96)
// (144,  72)

// path

// go dump balls
	// move x + 24
	// rotate right 90
	// move y - 3
	// dump balls
	// move y + 3
// pickup balls at (48, 48)
	// rotate left 135
	// approach
	// pickup routine
	// reverse path
// get balls at (72, 24)
// get balls at (72, 0)
// hang

*/

float currentx = 7.5;
float currenty = 36;

void go_to_point(float x, float y);
void get_balls_at_point(float x, float y);
void face_heading(float heading);

float heading_to_dxdy(float dx, float dy);
float dist_to_dxdy(float dx, float dy);
