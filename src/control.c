#include "control.h"

// input initialisation
Action inputAction(int ch){
    switch(ch){
        case 'W':
        case 'w':
        case KEY_UP:{
            return UP;
        }
        case 'S':
        case 's':
        case KEY_DOWN:{
            return DOWN;
        }
        case 'A':
        case 'a':
        case KEY_LEFT:{
            return LEFT;
        }
        case 'D':
        case 'd':
        case KEY_RIGHT:{
            return RIGHT;
        }
        case 'q':
        case 'Q':{
            return QUIT;
        }
        default:{
            return NONE;
        }
    }
}

// update on the direction
void updateDir(Action *dir, Action action){
    if(!dir){return;}
    else if(action == QUIT || action == NONE){return;}

    if(action == UP && *dir != DOWN){
        *dir = UP;
    }
    else if(action == DOWN && *dir != UP){
        *dir = DOWN;
    }
    else if(action == LEFT && *dir != RIGHT){
        *dir = LEFT;
    }
    else if(action == RIGHT && *dir != LEFT){
        *dir = RIGHT;
    }
}