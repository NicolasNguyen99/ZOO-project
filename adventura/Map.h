//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_MAP_H
#define ADVENTURA_MAP_H
#include <iostream>
#include <vector>
#include "Room.h"
#include "Team.h"

enum mapSizes{XS=4,M=5,L=6};
enum movementDirection{N,E,S,W};

class Map {
    std::vector<std::vector<Room*>> m_rooms;
    Team* m_team;
    Room* m_currentRoom;
    std::array<int,2> m_currentCoor;
    mapSizes m_size;
    void renderMap();
    void renderSmallMap();
    void renderMediumMap();
    void renderLargeMap();
    
public:
    std::array<int, 2> getCurrentCoor();
    Map(mapSizes size);
    void printMap();
    Room* getCurrentRoom();
    int getSize();
    void printMovementOptions();
    void moveTeam(movementDirection direction);
};


#endif //ADVENTURA_MAP_H
