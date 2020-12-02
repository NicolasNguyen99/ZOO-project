//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Tile.h"

Tile::Tile(){
    m_enemy = nullptr;
}

void Tile::printTile(bool isHeroStanding){
    std::cout << "  /\\";
//    if(m_enemy != nullptr){
//        std::cout << " /\\ " + m_enemy->getName() + " /\\ ";
//    }
    std::cout << (isHeroStanding ? " X " : "/\\");
    std::cout << "/\\  ";
}
