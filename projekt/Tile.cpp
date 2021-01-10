//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Tile.h"

Tile::Tile(){
    m_enemy = nullptr;
    m_chest = nullptr;
    m_isExplored = false;
}

objectsInTile Tile::getObjectsInTile(){
    return objectsInTile{m_chest};
}

void Tile::printTile(bool isHeroStanding){
    if(m_isExplored){
        std::cout << "  /\\";
        if(m_enemy != nullptr){
            std::cout << "E";
        }
        if(m_chest != nullptr){
            std::cout << "C";
        }
        if(isHeroStanding){
            std::cout << "H";
        }
        std::cout << "/\\  ";
    } else {
        std::cout << "  ???  ";
    }
}

void Tile::setEnemy(Enemy* enemy){
    m_enemy = enemy;
}

void Tile::killEnemy(){
    if(m_enemy != nullptr){
        delete m_enemy;
        m_enemy = nullptr;
    }
}

void Tile::setChest(Chest* chest){
    m_chest = chest;
}

void Tile::printEnemyStats(){
    m_enemy->printEnemyStats();
}

Enemy* Tile::getEnemy(){
    return m_enemy;
}

void Tile::removeChest(){
    if(m_chest != nullptr){
        m_chest = nullptr;
    }
}

void Tile::setIsExplored(){
    m_isExplored = true;
}

bool Tile::getIsExplored(){
    return m_isExplored;
}