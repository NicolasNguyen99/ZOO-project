//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Hero.h"

Hero::Hero(heroType type, std::string name){
    m_type = type;
    m_name = name;
    if(type == warrior){
        m_health = 150;
        m_strength = 30;
        m_abilityPower = 5;
    } else {
        if(type == mage){
            m_health = 100;
            m_strength = 10;
            m_abilityPower = 30;
        }
    }
}

std::string Hero::getName(){
    return m_name;
}

int Hero::getHealth(){
    return m_health;
}

int Hero::getStrength(){
    return m_strength;
}

int Hero::getAbilityPower(){
    return m_abilityPower;
};

std::string Hero::getItemName(Item item){
    return item.getName();
}