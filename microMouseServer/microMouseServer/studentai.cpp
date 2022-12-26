
#include "micromouseserver.h"
//#include<QDebug>
//#include<QThread>

void microMouseServer::studentAI()
{


/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/

if (counter==3 && counter3==3)
    foundFinish();

if (isWallRight() == false){
    turnRight();
    moveForward();
    counter = counter + 1;
}
else if (isWallLeft() && isWallRight() && isWallForward()){
    turnRight();
    moveForward();
    counter = 0;
    counter3 = 0;
}
else if(isWallForward() == true){
    turnRight();
    turnRight();
    counter3 = counter3 + 1;
}
else {
    moveForward();
    counter = 0;
    counter3 = 0;
}
}
