//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Hero.h"

Hero::Hero(std::string name, std::string profession):Character(name){
    m_abilityPower = 0;
    m_health = 100;
    m_strength = 10;
}

int Hero::getAbilityPower(){
    return m_abilityPower;
}