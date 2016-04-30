#pragma config(UserModel, "C:/Users/Jason Ouyang/Documents/RobotC Programs/32A-Config.c")

/**
* Simple Code Blocks
*
* Just the basic drive, firing, and angle adjustment, controlled with going from set speed to 0
*/

/**
* driveX tells the base to drive forward or backward depending on whether speed is positive or negative respectively
* @param speed -128 to 127
* @param time in mS
*/
void driveBaseX(int speed,unsigned int time)
{
	int brakespeed;
	motor[RightBase1]= speed;
	motor[RightBase2]= speed;
	motor[LeftBase1]= speed;
	motor[LeftBase2]= speed;
	sleep(time);
	//brakespeed is intended to provide more stopping force for 100 mS
	brakespeed = -1;
	motor[RightBase1]= brakespeed;
	motor[RightBase2]= brakespeed;
	motor[LeftBase1]= brakespeed;
	motor[LeftBase2]= brakespeed;
	sleep(100);
	//brakespeed here reduces the value to 0 to stop stressing the motors
	brakespeed = 0;
	motor[RightBase1]= brakespeed;
	motor[RightBase2]= brakespeed;
	motor[LeftBase1]= brakespeed;
	motor[LeftBase2]= brakespeed;
}
/**
*
* rotateBase tells the base to rotate clockwise or counterclockwise depending on speed is positive or negative respectively
* @param speed -128 to 127
* @param time in mS
*
*/
void rotateBase(int speed, unsigned int time)
{
	int brakespeed;
	motor[RightBase1]= -speed;
	motor[RightBase2]= -speed;
	motor[LeftBase1]= speed;
	motor[LeftBase2]= speed;
	sleep(time);
	//brakespeed is intended to provide more stopping force for 100 mS
	brakespeed = -1;
	motor[RightBase1]= -brakespeed;
	motor[RightBase2]= -brakespeed;
	motor[LeftBase1]= brakespeed;
	motor[LeftBase2]= brakespeed;
	sleep(100);
	//brakespeed here reduces the value to 0 to stop stressing the motors
	brakespeed = 0;
	motor[RightBase1]= -brakespeed;
	motor[RightBase2]= -brakespeed;
	motor[LeftBase1]= brakespeed;
	motor[LeftBase2]= brakespeed;
}

/**
 *
 * Base Speed just sets the speed of the two sides of the base.
 * @param LeftSpeed tells the motors on the left side of the base what speed to run at
 * @param RightSpeed does the same for the motors on the right side.
 *
 */

void BaseSpeed(int LeftSpeed, int RightSpeed)
{
	motor[LeftBase1] = LeftSpeed;
	motor[LeftBase2] = LeftSpeed;
	motor[RightBase1] = RightSpeed;
	motor[RightBase2] = RightSpeed;
}
/**
*
*Drive Functions
*
*Nothing fancy, just a threshold and direct user control over motors
*
*/

/**
*
*if the joystick value is above a set threshold, then the joystick will command the motor
*
*/
void JoystickBaseDrive()
{
	//threshold determines how far the stick can go before moving the robot
	int threshold = 10;
	if(abs(vexRT[Ch3]) >= threshold)
	{
		motor[RightBase1]= vexRT[Ch2];
		motor[RightBase2]= vexRT[Ch2];
	}
	else if (abs(vexRT[Ch3]) >= threshold)
	{
		motor[LeftBase1] = vexRT[Ch3];
		motor[LeftBase2] = vexRT[Ch3];
	}
	else if (abs(vexRT[Ch3]) <= threshold)
	{
		motor[LeftBase1] = 0;
		motor[LeftBase2] = 0;
	}
	else if (abs(vexRT[Ch2]) <= threshold)
	{
		motor[LeftBase1] = vexRT[Ch2];
		motor[LeftBase2] = vexRT[Ch2];
	}
}
