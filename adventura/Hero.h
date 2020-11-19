//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_HERO_H
#define ADVENTURA_HERO_H
#include <iostream>
#include "Item.h"

class Hero {
    std::string m_name;
    int health;
    int strength;
    Item* m_weapon;
    Item* m_armor;

public:
    Hero();
};


#endif //ADVENTURA_HERO_H
