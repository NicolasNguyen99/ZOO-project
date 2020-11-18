#include <iostream>
#include "Map.h"

int main() {
    Map* map = new Map(S);
    map->printMap(S);
    std::cout << map->getCurrentCoor().at(0) << std::endl;
    std::cout << map->getCurrentCoor().at(1) << std::endl;
    map->printMovementOptions();

    return 0;
}
