// The purpose of this program is to pick up one of the habitats on the road next to the small rover bay and place it on a small habitat construciton

#include <kipr/wombat.h>

int main()
{
    int claw = 3;
    int arm = 0;
    int up = 200;
    int down = 1400;
    int open = 1700;
    int closed = 1300;
    int pause = 500;
    enable_servos();
    set_servo_position(arm,up);
    set_servo_position(claw,open);
    cmpc(0);
    //Go Forward To Storage Docks
    while(gmpc(0) <= 7000)
    {
        motor(0,75);
        motor(3,75);
    }

    //Turn Left At Storage Docks
    cmpc(0);
    while(gmpc(0) <= 1300)
    {
        motor(0,75);
        motor(3,-50);
    }
    ao();
    //Go Forward To Line Up Horizontally With The Noodles
    while(gmpc(0) <= 2500)
    {
        motor(0,75);
        motor(3,75);
    }
    ao();

    //Turn To Face Noodles
    cmpc(0);
    while(gmpc(0) <= 1400)
    {
        motor(0,75);
        motor(3,-50);
    }
	/*
    //Lower Arm In order To Grab 1st Noodle
    set_servo_position(0,down);

    //Go To First Noodle
    cmpc(0);
    while(gmpc(0) <= 1800)
    {
        motor(0,75);
        motor(3,75);
    }
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    set_servo_position(claw,closed);
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    //Raise Arm
    set_servo_position(0,up);
	*/

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
	
    //Go To Line
    cmpc(0);
        while ((analog(0) < 1500) || (analog(1) < 1500))
    {
        if ((analog(0) < 1500) && (analog(1) < 1500))
        {
        motor(0,60);
        motor(3,60);
    }
    if ((analog(1) > 1500) && (analog(0) < 1500))
    {
     motor(3,80);
     motor(0,-80);
    }
    else if ((analog(1) < 1500) && (analog(0) > 1500))
    {
        motor(3,-80);
        motor(0,80);
    }
    }
    
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    //Go Back
    while(gmpc(0) >= 0)
    {
        motor(0,-75);
        motor(3,-75);
    }

    
        //Lower Arm In order To Grab 1st Noodle
    set_servo_position(0,down);

    //Go To First Noodle
    cmpc(0);
    while(gmpc(0) <= 1800)
    {
        motor(0,75);
        motor(3,75);
    }
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    set_servo_position(claw,closed);
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    //Raise Arm
    set_servo_position(0,up);

    //Back Up With First Noodle ----------------------------------------------------------------------------------
    cmpc(0);
    while(gmpc(0) >= -1000)
    {
        motor(0,-75);
        motor(3,-75);
    }
    ao();

    //Turn To Farthest Post
    cmpc(3);
    while(gmpc(3) <= 1000)
    {
        motor(0,-75);
        motor(3,75);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    int servo = up;
    while(servo < 850)
    {
        msleep(100);
        servo = servo + 50;
        set_servo_position(0,servo);
    }//------------------------------------------------------------------------------------    

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    //Back Up With First Noodle
    cmpc(0);
    while(gmpc(0) >= -200)
    {
        motor(0,-50);
        motor(3,-50);
    }
    
	//Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    servo = 850;
    while(servo < 1200)
    {
        msleep(100);
        servo = servo + 50;
        set_servo_position(0,servo);
    }//------------------------------------------------------------------------------------
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    //Open Claw
    int clawservo = closed;
    while(clawservo < open)
    {
        msleep(100);
        clawservo = clawservo + 10;
        set_servo_position(claw,clawservo);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
	
    
    //Backward
    cmpc(0);
    while(gmpc(0) >= -500)
    {
        motor(0,-50);
        motor(3,-50);
    }
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    set_servo_position(arm,up);

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    //Forward
    cmpc(0);
    while(gmpc(0) <= 300)
    {
        motor(0,50);
        motor(3,50);
    }

    //Turn Back To Face Poms
    cmpc(0);
    while(gmpc(0) <= 1300)
    {
        motor(0,75);
        motor(3,-50);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    set_servo_position(arm,down);

    //Go To Second Noodle
    cmpc(0);
    while(gmpc(0) <= 1800)
    {
        motor(0,75);
        motor(3,75);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    set_servo_position(claw,closed);

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    set_servo_position(arm,up);
    
    //Go To Line
    cmpc(0);
        while ((analog(0) < 1500) || (analog(1) < 1500))
    {
        if ((analog(0) < 1500) && (analog(1) < 1500))
        {
        motor(0,60);
        motor(3,60);
    }
    if ((analog(1) > 1500) && (analog(0) < 1500))
    {
     motor(3,80);
     motor(0,-80);
    }
    else if ((analog(1) < 1500) && (analog(0) > 1500))
    {
        motor(3,-80);
        motor(0,80);
    }
    }

    
    //Backward With 2nd Noodle
    cmpc(3);
    while(gmpc(3) >= -600)
    {
        motor(0,-75);
        motor(3,-75);
    }
    
    //Turn To Second Post
    cmpc(3);
    while(gmpc(3) <= 1100)
    {
        motor(0,-75);
        motor(3,75);
    }

    //Go To Second Post
    cmpc(0);
    while(gmpc(0) <= 300)
    {
        motor(0,75);
        motor(3,75);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    //Lower Arm To Post Height
    servo = up;
    while(servo < 750)
    {
        msleep(100);
        servo = servo + 50;
        set_servo_position(0,servo);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    set_servo_position(claw,open);

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    //Forward
    cmpc(0);
    while(gmpc(0) <= 200)
    {
        motor(0,50);
        motor(3,50);
    }
    
        //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    set_servo_position(arm,up);

    //Back Up From Second Post
    cmpc(0);
    while(gmpc(0) >= -600)
    {
        motor(0,-75);
        motor(3,-75);
    }
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    //Turn Back To Face Poms
    cmpc(0);
    while(gmpc(0) <= 1400)
    {
        motor(0,75);
        motor(3,-50);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);


    set_servo_position(claw,open);

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    set_servo_position(arm,down);

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    //Go To Third Noodle
    cmpc(0);
    while(gmpc(0) <= 800)
    {
        motor(0,75);
        motor(3,75);
    }

    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);

    set_servo_position(claw,closed);
    
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    set_servo_position(arm,up);
    
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    
    set_servo_position(claw,open);
    
    //Pause
    motor(0,0);
    motor(3,0);
    msleep(pause);
    disable_servos();
    return 0;
}

