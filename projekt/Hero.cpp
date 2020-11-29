//
// Created by Nicolas Nguyen on 24/11/2020.
//

#include "Hero.h"

Hero::Hero(){}

int Hero::getHealth(){
    return m_health;
};

Hero* Hero::createHero(infoToCreateHero info){
    Hero* newHero = new Hero();
    newHero->m_name = info.m_name;
    newHero->m_type = info.m_type;
    newHero->m_hasKey = false;
    if(info.m_type == heroType::Warrior){
        newHero->m_health = 200;
        newHero->m_strenght = 30;
        newHero->m_abilityPower = 5;
        //pridat mec
        //pridat heavy armor
    } else if(info.m_type == heroType::Ranger){
        newHero->m_health = 160;
        newHero->m_strenght = 20;
        newHero->m_abilityPower = 10;
        //pridat luk
        //pridat light armor
    } if(info.m_type == heroType::Mage){
        newHero->m_health = 140;
        newHero->m_strenght = 15;
        newHero->m_abilityPower = 30;
        //pridat hul
        //pridat magic armor
    }
    return newHero;
}