//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_TILE_H
#define PROJEKT_TILE_H
#include <iostream>
#include "Characters/Enemy.h"
#include "Chest.h"

struct objectsInTile{
    Chest* chest;
    //+suroviny, strom, kamen atd
};

class Tile {
    bool m_isExplored;
    Enemy* m_enemy;
    Chest* m_chest;

public:
    Tile();
    void printTile(bool isHeroStanding);
    void setEnemy(Enemy* enemy);
    void setChest(Chest* chest);
    Enemy* getEnemy();
    void removeChest();
    void killEnemy();
    void printEnemyStats();
    objectsInTile getObjectsInTile();
    void setIsExplored();
    bool getIsExplored();
};

#endif //PROJEKT_TILE_H
