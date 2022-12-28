
#include "micromouseserver.h"
#include<QDebug>
#include<QThread>

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

int row = this->curRow;
int column = this->curColumn;

values result = getValues(column,row);

counter = counter + 1;

if (counter < 500) {
    qWarning() << "row = " << row;
    qWarning() << "column = " << column;
    qWarning() << "top = " << result.top;
    qWarning() << "bottom = " << result.bottom;
    qWarning() << "left = " << result.left;
    qWarning() << "right = " << result.right;

    qWarning() << this->posStatus[column][row];
    qWarning() << this->maze->mouseDir();

if (result.right == 0 && this->posStatus[column+1][row] <= 2) {
    qWarning() << "right";
    if(this->maze->mouseDir() == dUP)
        turnRight();
    if(this->maze->mouseDir() == dDOWN)
        turnLeft();
    if(this->maze->mouseDir() == dLEFT) {
        turnRight();
        turnRight();
    }
    moveForward();
    this->curColumn  += 1;
    this->posStatus[column+1][row] += 1;
}
else if (result.left == 0 && this->posStatus[column-1][row] <= 2) {
    qWarning() << "left";
    if(this->maze->mouseDir() == dDOWN)
        turnRight();
    if(this->maze->mouseDir() == dUP)
        turnLeft();
    if(this->maze->mouseDir() == dRIGHT) {
        turnRight();
        turnRight();
    }
    moveForward();
    this->curColumn  -= 1;
    this->posStatus[column-1][row] += 1;
}
else if (result.top == 0 && this->posStatus[column][row+1] <= 2) {
    qWarning() << "top";
    if(this->maze->mouseDir() == dLEFT)
        turnRight();
    if(this->maze->mouseDir() == dRIGHT)
        turnLeft();
    if(this->maze->mouseDir() == dDOWN) {
        turnRight();
        turnRight();
    }
    moveForward();
    this->curRow += 1;
    this->posStatus[column][row+1] += 1;
}
else if (result.bottom == 0 && this->posStatus[column][row-1] <= 2) {
    qWarning() << "bottom";
    if(this->maze->mouseDir() == dRIGHT)
        turnRight();
    if(this->maze->mouseDir() == dLEFT)
        turnLeft();
    if(this->maze->mouseDir() == dUP) {
        turnRight();
        turnRight();
    }
    moveForward();
    this->curRow -= 1;
    this->posStatus[column][row-1] += 1;
}
}
}

/*
switch (this->maze->mouseDir()) {
case dUP:
    return mover->isWallRight();
    break;
case dDOWN:
    return mover->isWallLeft();
    break;
case dLEFT:
    return mover->isWallTop();
    break;
case dRIGHT:
    return mover->isWallBottom();
    break;
}
*/
