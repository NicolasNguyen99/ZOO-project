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
    Room(bool isAccessible, Enemy* enemy);
public:
    Room();
    Room(bool isAccessible);
    Room(Enemy* enemy);
    bool getIsAccessible();
    bool getIsExplored();
    ~Room();
};


#endif //ADVENTURA_ROOM_H