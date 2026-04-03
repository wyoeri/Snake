#ifndef FOOD_H
#define FOOD_H

#include <stdint.h>
#include "generator.h"

// a structure that stores the location coordinates of food
typedef struct{
    uint8_t foodX_; 
    uint8_t foodY_;
} foodPosition;

// the control function for coordinate generation and food rendering
foodPosition spawnFood(rng_t *rng, uint32_t minX, uint32_t maxX, uint32_t minY, uint32_t maxY);

// generation of food coordinates
uint32_t genFoodX(rng_t *rng, uint32_t min, uint32_t max);
uint32_t genFoodY(rng_t *rng, uint32_t min, uint32_t max);

#endif