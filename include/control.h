#ifndef CONTROL_H
#define CONTROL_H

// storing possible actions upon input
typedef enum{
    UP, 
    DOWN,
    RIGHT,
    LEFT, 
    NONE, 
    QUIT
} userAction;

// input initialisation
userAction inputUserAction(int ch); 

// update on the direction
void updateDir(userAction *dir, userAction action);

#endif