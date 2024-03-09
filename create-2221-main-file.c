#include <kipr/wombat.h>
float drift = -24.96; // get rid of the drift >:(

int main()
{
    create_connect();
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
        
    void turn(speedl,speedr,angle){
     set_create_total_angle(0);
     
     if (get_create_total_angle() < angle) {
         while (get_create_total_angle() < angle) { // turns bot to the left use positive numbers
             create_drive_direct(-speedl,speedr);
         }
     }
     else if (get_create_total_angle() > angle){ //this is to turn right use negative numbers you 
         while (get_create_total_angle() > angle) {
             create_drive_direct(speedl,-speedr);
             
         }
     }
       
    }
    
	move(100,100, -1500);
    
    turn(100, 100, 90);
    
    
    create_disconnect();
    
    return 0;
}
