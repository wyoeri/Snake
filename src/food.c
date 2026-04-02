#include "food.h"

#include "curses_wrapper.h"

// the control function for coordinate generation and food rendering
food_position spawnFood(rng_t *rng, uint32_t minX, uint32_t maxX, uint32_t minY, uint32_t maxY){
    food_position food_pos;

    food_pos.foodX_ = genFoodX(rng, minX, maxX);
    food_pos.foodY_ = genFoodY(rng, minY, maxY);

    drawFood(&food_pos);

    return food_pos;
}

// food illustration
void drawFood(const food_position *food_pos){
    mvprintw(food_pos->foodY_, food_pos->foodX_, "@");
}

// generation of food coordinates
uint32_t genFoodX(rng_t *rng, uint32_t min, uint32_t max){
    return rngRange(rng, min, max);
}

uint32_t genFoodY(rng_t *rng, uint32_t min, uint32_t max){
    return rngRange(rng, min, max);
}