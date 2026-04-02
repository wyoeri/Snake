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
} Action;

// input initialisation
Action inputAction(int ch); 

// update on the direction
void updateDir(Action *dir, Action action);

#endif