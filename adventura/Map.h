//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_MAP_H
#define ADVENTURA_MAP_H
#include <iostream>
#include <vector>
#include "Room.h"

enum mapSizes{S=3,M=4,L=5};

class Map {
    std::vector<std::vector<Room*>> m_rooms;
    mapSizes m_size;

public:
    Map(mapSizes size);
    void renderMap(int size);
    void renderSmallMap(int size);
    void renderMediumMap(int size);
    void renderLargeMap(int size);
    void printMap(int size);
};


#endif //ADVENTURA_MAP_H
