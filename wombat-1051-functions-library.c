#include <kipr/wombat.h>
#include "mylibrary.h"

//move servo up slowly
void upslow (int arm, int initial, int final, int speed)
{	
	set_servo_position(arm, initial);
    msleep(500);
    int counter = initial;
    while (get_servo_position(arm) < final) 
    {
        set_servo_position(arm, counter);
        counter = counter + speed;
        msleep(20);
    }
}

//move servo down slowly
void downslow (int arm, int initial, int final, int speed)
{	
	set_servo_position(arm, initial);
    msleep(500);
    int counter = initial;
    while (get_servo_position(arm) > final) 
    {
        set_servo_position(arm, counter);
        counter = counter - speed;
        msleep(20);
    }
}

//move servo
void s (int port, int pos)
{
    motor(0,0);
    motor(3,0);
    msleep(200);
    set_servo_position(port, pos);
    msleep(500);
    motor(0,0);
    motor(3,0);
    msleep(200);

}

//square up on the black line - going forward
void forsquare ()
{
while ((analog(0) < 900) || (analog(1) < 900))
        {
            if ((analog(0) > 900) && (analog(1) < 900))
            {
                motor(0,0);
                motor(3,20);
            }
            else if ((analog(0) < 900) && (analog(1) > 900))
            {
                motor(0,20);
                motor(3,0);
            }
            else
            {
                motor(0,30);
                motor(3,30);
            }
        }
        ao();
        msleep(200);
}

//square up on the black line - going backwards
void backsquare ()
{
while ((analog(0) < 900) || (analog(1) < 900))
        {
            if ((analog(0) > 900) && (analog(1) < 900))
            {
                motor(0,0);
                motor(3,20);
            }
            else if ((analog(0) < 900) && (analog(1) > 900))
            {
                motor(0,-20);
                motor(3,0);
            }
            else
            {
                motor(0,-30);
                motor(3,-30);
            }
        }
        ao();
        msleep(200);
}

//follow the line
void follow (int distance)
{
	int counter = distance;
	while (counter < 2700)
	{
		if (analog(1) > 2600)
		{
			motor(0, 5);
			motor(3, 50);
			counter += 1;
		}
		else
		{
			motor(0, 50);
			motor(3, 5);
			counter += 1;
		}
	}
}

//turn left 90 degrees
void L90 ()
{
cmpc(0);
    while (gmpc(0)< (1379-275))
    {
        motor(0,50);
        motor(3,-50);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}

//turn right 90 degrees
void R90 ()
{
cmpc(3);
    while (gmpc(3)< (1379-275))
    {
        motor(0,-50);
        motor(3,50);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}   

//turn left 45 degrees
void L45 ()
{
cmpc(0);
    while (gmpc(0)< (1379-275)*.5)
    {
        motor(0,50);
        motor(3,-50);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}   

//turn right 45 degrees
void R45 ()
{
cmpc(3);
    while (gmpc(3)< (1379-275)*.5)
    {
        motor(0,-50);
        motor(3,50);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}   

//move forward with motor position counter
void forward(int power, int distance)
{
    
    cmpc(0);
    while (gmpc(0) < distance) 
    {
        motor(0,power);
        motor(3,power);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}

//move backward with motor position counter
void backward(int power, int distance)
{
    
    cmpc(0);
    while (gmpc(0) > -distance) 
    {
        motor(0,-power);
        motor(3,-power);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}

//turn left with motor position counter
void L (int dist)
{
cmpc(0);
    while (gmpc(0)< (dist))
    {
        motor(0,50);
        motor(3,-50);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}

//turn right with motor position counter
void R (int dist2)
{
cmpc(3);
    while (gmpc(3)< (dist2))
    {
        motor(0,-50);
        motor(3,50);
    }
    motor(0,0);
    motor(3,0);
    msleep(500);
}   

//stop for a set time
void stop (int time)
{
    motor(0,0);
    motor(3,0);
    msleep(time);
}
