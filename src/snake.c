#include "snake.h"

#include "curses_wrapper.h"

// snake initialization
void initSnake(stateSnake *state_snake, const startSnakePosition *start_snake){
    if(!state_snake || !start_snake){return;}
    state_snake->sizeSnake_ = 1;
    state_snake->snakeX_[0] = start_snake->startSnakeX_;
    state_snake->snakeY_[0] = start_snake->startSnakeY_;
}

// the snake's movements
void moveSnake(stateSnake *state_snake, userAction user_action){
    for(uint16_t i = state_snake->sizeSnake_ - 1; i > 0; i--){
        state_snake->snakeX_[i] = state_snake->snakeX_[i - 1];
        state_snake->snakeY_[i] = state_snake->snakeY_[i - 1];
    }

    switch(user_action){
        case UP:{
            state_snake->snakeY_[0]--;
            break;
        }
        case DOWN:{
            state_snake->snakeY_[0]++;
            break;
        }
        case LEFT:{
            state_snake->snakeX_[0]--;
            break;
        }
        case RIGHT:{
            state_snake->snakeX_[0]++;
            break;
        }
        default:{
            break;
        }
    }
}