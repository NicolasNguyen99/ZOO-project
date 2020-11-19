#include <iostream>
#include "Map.h"

int main() {
    Map* map = new Map(XS);
    map->printMap();
//    std::cout << map->getCurrentCoor().at(0) << " ";
//    std::cout << map->getCurrentCoor().at(1) << std::endl;
//    map->printMovementOptions();
//    map->moveTeam(N);
//    std::cout << map->getCurrentCoor().at(0) << " ";
//    std::cout << map->getCurrentCoor().at(1) << std::endl;
    return 0;
}
