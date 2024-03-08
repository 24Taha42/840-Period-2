#include <kipr/wombat.h>
#include "mylibrary.h"
int main()
{
//Start of Code:
    
    //enable servos
    enable_servos();
    
//open airlock:
    
    //square up on top edge of start box
    forsquare (); 
    
    //sets the claw to correct starting position
    s(3, 1100);
    
    //turn left towards airlock
    L (335);
    
    //goes forward towards airlock from start box a little bit
    forward(75, 952);
    
    //slowly lowers the arm to the correct position to open the airlock
    downslow (0, 900, 350, 3);
    
    //pause
    stop (500);
    
    //goes forward to position to open airlock
    forward(75, 1200);
    
    //closes claw around airlock
    s(3, 600);
    
    //goes backwards to open airlock
    backward(50, 1500);
    
    //opens claw to let go of airlock
    s(3, 1300);
    
    //raises arm up so that it is in position to turn around to pick up habitat
    s(0,2000);
    
    //moves backwards further away from airlock and towards vertical storage rack
    backward(50, 200);
    
    //turns right towards vertical storage rack to be in position to get habitat
	R (1200);
    
    //goes backwards and squares up on the black line before getting the habitat
    backward(80, 720);
    backsquare ();
    
//get habitat:
    
    //raises arm so that it is position to get habitat
    s(0,1000);

    //closes claw around top habitat
    s(3,960);
    
    //slowly raises arm lifting the habitat off of the storage rack
    upslow (0, 1200, 1700, 7);
    
//put habitat on habitat construction pole:
    
    //turns left away from the storage rack and towards the habitat construction poles
    L90();
    

//END OF CODE:
    
    //disables servos
    disable_servos();
    return 0;
}
