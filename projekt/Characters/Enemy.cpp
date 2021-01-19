//
// Created by Nicolas Nguyen on 01/12/2020.
//

#include "Enemy.h"

unsigned int Enemy::s_enemyNum = 0;

Enemy::Enemy(int level):Character("Enemacek", 100, 20){
    s_enemyNum++;
    m_level = level;
    m_Xp = 30+(m_level*5);
};

void Enemy::printEnemyStats(){
    std::cout << m_name + " stats: " << std::endl;
    std::cout << "  -level: " << m_level << std::endl;
    std::cout << "  -health: " << m_currentHealth << "/" << m_maxHealth<< std::endl;
    std::cout << "  -strength: " << m_strength << std::endl;
}

int Enemy::getXpReward(){
    return m_Xp;
}

unsigned int Enemy::getEnemyNum(){
    return s_enemyNum;
}

Enemy::~Enemy(){
    s_enemyNum--;
}