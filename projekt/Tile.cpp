//
// Created by Nicolas Nguyen on 23/11/2020.
//

#include "Tile.h"

Tile::Tile(tileType type, bool isLocked){
    m_type = type;
    m_isLocked = isLocked;
    m_isExplored = false;
}

tileType Tile::getType(){
    return m_type;
}

bool Tile::getIsExplored(){
    return m_isExplored;
}

bool Tile::getIsLocked(){
    return m_isLocked;
}

//Enemy* getEnemy();

Tile::~Tile(){

}