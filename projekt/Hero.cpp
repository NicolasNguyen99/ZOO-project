//
// Created by Nicolas Nguyen on 02/12/2020.
//

#include "Hero.h"

Hero::Hero(std::string name, int health, int strength):Character(name, health, strength){
    m_abilityPower = 0;
}

int Hero::getAbilityPower(){
    return m_abilityPower;
}