#include "generator.h"

// initialize generator with a seed value 
void rng_seed(rng_t *r, uint32_t seed){
    if(seed == 0){seed = 0xACE1;}
    r->state_ = seed;
}

// generation of the next random number
uint32_t rng_next(rng_t *r){
    r->state_ ^= r->state_ << 13; // shift left by 13 bits
    r->state_ ^= r->state_ >> 17; // shift right by 17 bits
    r->state_ ^= r->state_ << 5; // shift left by 5 bits
    return r->state_; 
}

// generation of the random number in specified range
uint32_t rng_range(rng_t *r, uint32_t min, uint32_t max){
    return min + (rng_next(r) % (max - min + 1));
}