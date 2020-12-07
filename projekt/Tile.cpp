//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Tile.h"

Tile::Tile(Enemy* enemy, Chest* chest){
    m_enemy = enemy;
    m_chest = chest;
}

Tile::Tile():Tile(nullptr, nullptr){}

Tile::Tile(Enemy* enemy):Tile(enemy, nullptr){}

Tile::Tile(Chest* chest):Tile(nullptr, chest){}

void Tile::printTile(bool isHeroStanding){
    std::cout << "  /\\";
    if(m_enemy != nullptr){
        std::cout << "E";
    }
    if(m_chest != nullptr){
        std::cout << "CH";
    }
    std::cout << (isHeroStanding ? " H " : "/\\");
    std::cout << "/\\  ";
}
