//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_TILE_H
#define PROJEKT_TILE_H
#include <iostream>
#include "Enemy.h"
#include "Chest.h"

class Tile {
    //kdyztak na konci implementace, po spawnu chestek a ememy
    //bool m_isExplored;
    Enemy* m_enemy;
    Chest* m_chest;

public:
    Tile(Enemy* enemy, Chest* chest);
    Tile(Enemy* enemy);
    Tile(Chest* chest);
    Tile();
    void printTile(bool isHeroStanding);
};

#endif //PROJEKT_TILE_H
