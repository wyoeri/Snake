#ifndef SNAKE_H
#define SNAKE_H

#include <stdint.h>

// the starting coordinates of the snake
typedef struct{
    uint8_t startX_;
    uint8_t startY_;
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
    an array of 1280 elements, as the map’s area is 1250 (50×25), 
    plus 30 bytes because this number is a multiple of 16, 32 and 64, 
    which makes the processor’s job easier
*/

// snake initialization
void initSnake(stateSnake *state_snake, const startSnakePosition *start_snake);

// drawing a snake
void drawSnake(const stateSnake *state_snake);

#endif