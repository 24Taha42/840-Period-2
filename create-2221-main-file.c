// The purpose of this program is to move the create toward the space dock switch

#include <kipr/wombat.h>
float drift = -24.96; // get rid of the drift >:(

// This function allows the robot to move forward and backward linearly
void move(float speedl,int speedr, int dis){
	set_create_distance(0);
	if (dis > 0) {
		while(get_create_distance() < dis){
		create_drive_direct(speedl - drift, speedr);
		}
	}
	else if (dis < 0) {
		while (get_create_distance() > dis){
		create_drive_direct(-speedl + drift, -speedr);
		}
	}
}

// This function rotates the create in place if the two speeds are equal or else arcs the create to a certain angle
void turn(speedl,speedr,angle){
	set_create_total_angle(0);

	// turns bot to the left - use a positive value for angle
	if (get_create_total_angle() < angle) {
		while (get_create_total_angle() < angle) { 
		create_drive_direct(-speedl,speedr);
		}
	}
	// turns the bot to the /right/ - use a /negative/ value for the angle
	else if (get_create_total_angle() > angle){  
		while (get_create_total_angle() > angle) {
		create_drive_direct(speedl,-speedr);
		}
	}

}


int main()
{
	create_connect();
	// moves the create out of the start box
	move(100,100, -1500);
	// turns to face the light switch
	turn(100, 100, 90);
	
	
	create_disconnect();
	
	return 0;
}
