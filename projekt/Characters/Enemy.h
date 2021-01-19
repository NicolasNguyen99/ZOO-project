//
// Created by Nicolas Nguyen on 01/12/2020.
//

#ifndef PROJEKT_ENEMY_H
#define PROJEKT_ENEMY_H
#include "Character.h"

class Enemy:public Character{
    static unsigned int s_enemyNum;
    unsigned int m_level;
    std::string m_race;
    int m_Xp;

public:
    Enemy(int level);
    void printEnemyStats();
    int getXpReward();
    unsigned int getEnemyNum();
    ~Enemy();
};


#endif //PROJEKT_ENEMY_H
