//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Tile.h"

Tile::Tile(){
    m_enemy = nullptr;
    m_chest = nullptr;
}

objectsInTile Tile::getObjectsInTile(){
    return objectsInTile{m_chest, m_enemy};
}

void Tile::printTile(bool isHeroStanding){
    std::cout << "  /\\";
    if(m_enemy != nullptr){
        std::cout << "E";
    }
    if(m_chest != nullptr){
        std::cout << "CH";
    }
    if(isHeroStanding){
        std::cout << " H ";
    }

    std::cout << "/\\  ";
}

void Tile::setEnemy(Enemy* enemy){
    m_enemy = enemy;
}

void Tile::setChest(Chest* chest){
    m_chest = chest;
}

Enemy* Tile::getEnemy(){
    return m_enemy;
}