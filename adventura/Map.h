//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_MAP_H
#define ADVENTURA_MAP_H
#include <iostream>
#include <vector>
#include <array>
#include "Room.h"

enum mapSizes{XS=4,M=5,L=6};

class Map {
    std::vector<std::vector<Room*>> m_rooms;
    Room* m_currentRoom;
    std::array<int,2> m_currentCoor;
    mapSizes m_size;
    void renderMap();
    void renderSmallMap();
    void renderMediumMap();
    void renderLargeMap();

public:
    Map(mapSizes size);
    std::array<int, 2> getCurrentCoor();
    void printMap();
    Room* getCurrentRoom();
    int getSize();
    void printMovementOptions();
    std::vector<std::vector<Room*>> getRooms();
    void setCurrentCoor(int x, int y);
    void setCurrentRoom(Room* currentRoom);
};


#endif //ADVENTURA_MAP_H
