//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_TEAM_H
#define ADVENTURA_TEAM_H
#include "Hero.h"
#include <vector>
#include "Room.h"
#include "Inventory.h"

enum movementDirection{N,E,S,W};

class Team {
    std::array<Hero*, 2> m_team;
    bool m_haveKey;
    int m_gold;
    Inventory* m_inventory;

public:
    Team();
    void moveTeam(std::vector<std::vector<Room*>> &rooms, Room* &currentRoom, std::array<int, 2> &currentCoor, movementDirection direction);
};


#endif //ADVENTURA_TEAM_H
