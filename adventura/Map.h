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

struct positionCoor{
    int x;
    int y;
};

class Map {
    std::vector<std::vector<Room*>> m_rooms;
    Room* m_currentRoom;
    positionCoor m_currentCoor;
    mapSizes m_size;
    void renderMap();
    void renderSmallMap();
    void renderMediumMap();
    void renderLargeMap();

public:
    Map(mapSizes size);
    positionCoor getCurrentCoor();
    Room* getCurrentRoom();
    int getSize();
    std::vector<std::vector<Room*>> getRooms();
    void setCurrentCoor(positionCoor currentCoor);
    void setCurrentRoom(Room* currentRoom);
    void printMap();
    void printMovementOptions();
};


#endif //ADVENTURA_MAP_H
