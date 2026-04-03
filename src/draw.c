#include "draw.h"

#include <stddef.h>
#include "curses_wrapper.h"

// rendering the map based on the initialised values
void drawMap(const map_t *map){
    for(size_t i = 0; i < HEIGHT_MAP; i++){
        for(size_t j = 0; j < WIDTH_MAP; j++){
            if(map->map_[i][j] == 1){
                mvaddch(i, j, '#');
            }
            else{
                mvaddch(i, j, ' ');
            }
        }
    }
}

// food illustration
void drawFood(const foodPosition *food_position){
    mvaddch(food_position->foodY_, food_position->foodX_, '@');
}

// drawing a snake
void drawSnake(const stateSnake *state_snake){
    mvaddch(state_snake->snakeY_[0], state_snake->snakeX_[0], 'O');

    for(uint16_t i = 1; i < state_snake->sizeSnake_; i++){
        mvaddch(state_snake->snakeY_[i], state_snake->snakeX_[i], 'o');
    }
}