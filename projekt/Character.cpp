//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Character.h"

Character::Character(std::string name, int health, int strength){
    m_name = name;
    m_health = health;
    m_strength = strength;
}

std::string Character::getName(){
    return m_name;
}

int Character::getHealth(){
    return m_health;
}

int Character::getStrength(){
    return m_strength;
}
