//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_TILE_H
#define PROJEKT_TILE_H
#include <iostream>
#include "Enemy.h"

class Tile {
    bool m_isLocked;
    bool m_isExplored;
    Enemy* m_enemy;

public:
    Tile();
    void printTile(bool isHeroStanding);
};

#endif //PROJEKT_TILE_H
