//
// Created by Nicolas Nguyen on 24/11/2020.
//

#ifndef PROJEKT_GAME_H
#define PROJEKT_GAME_H
#include "Map.h"
#include "Hero.h"

class Game {
    Map* m_map;
    Hero* m_hero;
    void communication();
    void printMainMenu();
    void printChooseDialog();
    int getInput();
    void printHelp();
    void setGame();
    void setHero();
    void setMap();

public:
    Game();
    void printMovementOptions();
    void moveHero(movementDirection direction);
    void printMap();
//    positionCoor getCurrentCoor();
};


#endif //PROJEKT_GAME_H
