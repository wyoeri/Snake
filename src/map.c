#include "map.h"

#include <stddef.h>
#include "curses_wrapper.h"

// map initialisation
void initMap(map_t *map){
    for(size_t i = 0; i < HEIGHT_MAP; i++){
       for(size_t j = 0; j < WIDTH_MAP; j++){
			if(i == 0 || i == HEIGHT_MAP - 1 || j == 0 || j == WIDTH_MAP - 1){
                map->map_[i][j] = 1;
            }
            else{
                map->map_[i][j] = 0;
            }
	   } 
    }
}
/*
    1. i == 0 || i == HEIGHT_MAP - 1 - identifies the top and bottom boundaries of the map.
    2. j == 0 || j == WIDTH_MAP - 1 - identifies the leftmost and rightmost columns.
    if any of these conditions are met, the cell is marked as a wall (1), creating a solid perimeter for the play area.
*/