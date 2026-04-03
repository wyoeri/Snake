#ifndef MAP_H
#define MAP_H

#include <stdint.h>
#include <stddef.h>

#define HEIGHT_MAP 25
#define WIDTH_MAP 50

typedef struct{
    uint8_t map_[HEIGHT_MAP][WIDTH_MAP];
} map_t;

// map initialisation
void initMap(map_t *map);

#endif