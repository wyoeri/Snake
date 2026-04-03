#ifndef DRAW_H
#define DRAW_H

#include "map.h"
#include "food.h"
#include "snake.h"

// rendering the map based on the initialised values
void drawMap(const map_t *map);

// food illustration
void drawFood(const foodPosition *food_position);

// drawing a snake
void drawSnake(const stateSnake *state_snake);

#endif