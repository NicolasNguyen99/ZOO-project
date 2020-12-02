//
// Created by Nicolas Nguyen on 24/11/2020.
//

#ifndef PROJEKT_HERO_H
#define PROJEKT_HERO_H
#include <iostream>
#include "Item.h"

enum class heroType{Warrior, Ranger, Mage};

struct infoToCreateHero{
    std::string m_name;
    heroType m_type;
};

class Hero {
    std::string m_name;
    heroType m_type;
    int m_health;
    int m_strenght;
    int m_abilityPower;
    bool m_hasKey;
    Item* m_weapon;
    Item* m_armor;
    Hero();

public:
    Hero* createHero(infoToCreateHero info);
    int getHealth();
};


#endif //PROJEKT_HERO_H
