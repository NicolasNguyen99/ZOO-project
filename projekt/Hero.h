//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_HERO_H
#define PROJEKT_HERO_H
#include "Character.h"

class Hero:public Character{
    int m_abilityPower;
    bool m_haveKey;

public:
    Hero(std::string name, int health, int strength);
    int getAbilityPower();
};


#endif //PROJEKT_HERO_H
