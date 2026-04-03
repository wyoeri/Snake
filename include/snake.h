#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>
#include "control.h"

// the starting coordinates of the snake
typedef struct{
    uint8_t startSnakeX_;
    uint8_t startSnakeY_;
} startSnakePosition;

typedef struct{
    uint8_t snakeX_;
    uint8_t snakeY_;
} snakePosition;

// the state of the snake
typedef struct{
    uint16_t sizeSnake_;
    uint8_t snakeX_[1280]; 
    uint8_t snakeY_[1280];
} stateSnake;
/*
    arrays of 1,280 elements, as the map’s area is 1,250 (50×25), 
    plus 30 bytes, since this number is a multiple of 16, 32 and 64, 
    which makes the processor’s job easier
*/

// snake initialization
void initSnake(stateSnake *state_snake, const startSnakePosition *start_snake);

// the snake's movements
void moveSnake(stateSnake *state_snake, userAction user_action);

#endif