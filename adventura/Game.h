//
// Created by Nicolas Nguyen on 19/11/2020.
//

#ifndef ADVENTURA_GAME_H
#define ADVENTURA_GAME_H
#include "Map.h"
#include "Team.h"

class Game {
    Map* m_map;
    Team* m_team;

public:
    Game();
    void printMovementOptions();
    void moveTeam(movementDirection direction);
    void printMap();
    std::array<int, 2> getCurrentCoor();
};


#endif //ADVENTURA_GAME_H
