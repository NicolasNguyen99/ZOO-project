//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_TEAM_H
#define ADVENTURA_TEAM_H
#include "Hero.h"
#include "Inventory.h"

class Team {
    std::array<Hero*, 2> m_team;
    bool m_haveKey;
    int m_gold;
    Inventory* m_inventory;

public:
    Team();

};


#endif //ADVENTURA_TEAM_H
