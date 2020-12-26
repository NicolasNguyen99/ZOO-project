//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Enemy.h"

Enemy::Enemy(int level):Character("Enemacek", 100, 20){
    m_level = level;
    m_Xp = level*5;
};