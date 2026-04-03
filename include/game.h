#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "generator.h"
#include "map.h"
#include "snake.h"
#include "control.h"
#include "food.h"

#define VALUETIMEOUT 175

#define MIN_Y 1
#define MAX_Y 48
#define MIN_X 1
#define MAX_X 23
#define MAX_SIZE_SNAKE 1280

typedef struct{
    uint16_t score_;
    bool gameover_;
    rng_t r_;
    map_t m_;
    foodPosition food_pos_;
    startSnakePosition start_snake_pos_;
    snakePosition snake_pos_;
    stateSnake state_snake_;
    userAction user_action_;
    userAction user_action_dir_;
} stateGame;

// main game loop 
void gameLoop(void);

// display statistics before returning to the menu
void gameover(stateGame *game);

// initialisation of the game's starting state
void initGame(stateGame *game);

// checking whether the snake collides with anything
bool checkCollidedSnakeWall(stateGame *game);
bool checkCollidedSnakeFood(stateGame *game);
bool checkCollidedSnakeHeadBody(stateSnake *snake);
foodPosition checkSpawnFoodSnakeBody(stateGame *game, stateSnake *snake);

// statistical output
void displayScore(stateGame *game);
void displaySizeSnake(stateGame *game);

#endif