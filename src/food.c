#include "food.h"

#include "curses_wrapper.h"

// the control function for coordinate generation and food rendering
foodPosition spawnFood(rng_t *rng, uint32_t minX, uint32_t maxX, uint32_t minY, uint32_t maxY){
    foodPosition food_position;

    food_position.foodX_ = (uint8_t)genFoodX(rng, minX, maxX);
    food_position.foodY_ = (uint8_t)genFoodY(rng, minY, maxY);

    return food_position;
}

// generation of food coordinates
uint32_t genFoodX(rng_t *rng, uint32_t min, uint32_t max){
    return rngRange(rng, min, max);
}

uint32_t genFoodY(rng_t *rng, uint32_t min, uint32_t max){
    return rngRange(rng, min, max);
}