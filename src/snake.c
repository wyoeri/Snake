#include "snake.h"

#include "curses_wrapper.h"

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

// the snake's movements
void moveSnake(stateSnake *ss, userAction ua){
    for(uint16_t i = ss->sizeSnake_ - 1; i > 0; i--){
        ss->snakeX_[i] = ss->snakeX_[i - 1];
        ss->snakeY_[i] = ss->snakeY_[i - 1];
    }

    switch(ua){
        case UP:{
            ss->snakeY_[0]--;
            break;
        }
        case DOWN:{
            ss->snakeY_[0]++;
            break;
        }
        case LEFT:{
            ss->snakeX_[0]--;
            break;
        }
        case RIGHT:{
            ss->snakeX_[0]++;
            break;
        }
        default:{
            break;
        }
    }
}