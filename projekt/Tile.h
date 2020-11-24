//
// Created by Nicolas Nguyen on 23/11/2020.
//

#ifndef PROJEKT_TILE_H
#define PROJEKT_TILE_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <array>

enum class tileType{
    Forrest,
    Swamp,
    Mountain,
};

class Tile {
protected:
    tileType m_type;
    bool m_isExplored;
    bool m_isLocked;
    //Enemy* m_enemy;
    void printEnemy();

public:
    Tile(tileType type, bool isLocked);
    Tile(tileType type);
    tileType getType();
    bool getIsExplored();
    bool getIsLocked();
    //Enemy* getEnemy();
    virtual void printPattern(int rowNum) = 0;
    virtual ~Tile();
};


#endif //PROJEKT_TILE_H
