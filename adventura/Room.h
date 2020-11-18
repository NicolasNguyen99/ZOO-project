//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_ROOM_H
#define ADVENTURA_ROOM_H
#include "Enemy.h"

class Room {
    bool m_isAccessible;
    bool m_isExplored;
    Enemy* m_enemy;
public:
    Room();
    Room(bool isAccessible);
    bool getIsAccessible();
    bool getIsExplored();
};


#endif //ADVENTURA_ROOM_H
