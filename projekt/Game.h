//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_GAME_H
#define PROJEKT_GAME_H
#include "Map.h"
#include "Hero.h"

class Game {
    Map* m_map;
    Hero* m_hero;
    void createHero();
    void createMap();

public:
    Game();
    void printLocationMap();
    void printTileMap();
    void printMovementOptions();
    void moveHero(movementDirection direction);

};


#endif //PROJEKT_GAME_H
