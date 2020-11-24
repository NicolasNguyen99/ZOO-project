#include <iostream>
#include "Map.h"

int main() {

//    Tile* tile = new Swamp(tileType::Swamp, false);
//    tile->printPattern();
//    Tile* tile1 = new Forrest(tileType::Forrest, false);
//    tile1->printPattern();
//    Tile* tile2 = new Mountain(tileType::Mountain, false);
//    tile2->printPattern();
    Map* map = new Map(mapSize::Small);
    map->printMap();
    return 0;
}