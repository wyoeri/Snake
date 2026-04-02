#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdint.h>

// XORShift32 random number generator state
typedef struct{
    uint32_t state_;
} rng_t;

// install initial generator seed 
void rng_seed(rng_t *r, uint32_t seed);

// generation of the next random number
uint32_t rng_next(rng_t *r);

// generation of the random number in specified range
uint32_t rng_range(rng_t *r, uint32_t min, uint32_t max);

#endif