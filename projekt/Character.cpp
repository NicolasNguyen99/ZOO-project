//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Character.h"

Character::Character(std::string name, int maxHealth, int strength){
    m_name = name;
    m_strength = strength;
    m_maxHealth = maxHealth;
    m_currentHealth = m_maxHealth;
}

std::string Character::getName(){
    return m_name;
}

int Character::getHealth(){
    return m_currentHealth;
}

int Character::getStrength(){
    return m_strength;
}
