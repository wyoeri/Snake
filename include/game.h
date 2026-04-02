#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "generator.h"
#include "map.h"
#include "snake.h"
#include "control.h"
#include "food.h"

#define VALUETIMEOUT 150

typedef struct{
    uint16_t score_;
    bool gameover_;
    rng_t r_;
    map_t m_;
    food_position fp_;
    startSnakePosition ssp_;
    snakePosition sp_;
    stateSnake ss_;
    userAction ua_;
    userAction uad_;
} stateGame;

// main game loop 
void gameLoop(void);

// initialisation of the game's starting state
void initGame(stateGame *state_game);

// checking whether the snake has collided with the wall
bool checkCollidedSnakeWall(stateGame *state_game);

#endif