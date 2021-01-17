//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_ENEMY_H
#define PROJEKT_ENEMY_H
#include "Character.h"

class Enemy:public Character{
    static unsigned int enemyNum;
    int m_level;
    std::string m_race;
    int m_Xp;

public:
    Enemy(int level);
    void printEnemyStats();
    int getXpReward();
};


#endif //PROJEKT_ENEMY_H
