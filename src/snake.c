#include "snake.h"

// snake initialization
void initSnake(stateSnake *state_snake, const startSnakePosition *start_snake){
    if(!state_snake || !start_snake){return;}
    state_snake->sizeSnake_ = 1;
    state_snake->snakeX_[0] = start_snake->startSnakeX_;
    state_snake->snakeY_[0] = start_snake->startSnakeY_;
}

// drawing a snake
void drawSnake(const stateSnake *state_snake){
    for(uint16_t i = 0; i < state_snake->sizeSnake_; i++){
        mvprintw(state_snake->snakeY_[i], state_snake->snakeX_[i], "o");
    }
}