//
// Created by Nicolas Nguyen on 26/12/2020.
//

#ifndef PROJEKT_GAMEPREPARE_H
#define PROJEKT_GAMEPREPARE_H
#include "Game.h"

class GamePrepare {
    Game* m_game;
    void getHelp();
    void createHero();
    void createMap();
    void setUpGame();

public:
    GamePrepare();
    void startMenu();
};


#endif //PROJEKT_GAMEPREPARE_H
