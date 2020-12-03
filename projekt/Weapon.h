//
// Created by Nicolas Nguyen on 03/12/2020.
//

#ifndef PROJEKT_WEAPON_H
#define PROJEKT_WEAPON_H
#include "Item.h"

class Weapon:public Item{
    int m_bonusStrength;

public:
    Weapon(std::string name, std::string type, int bonusStrength);
    int getBonusStrength();
};


#endif //PROJEKT_WEAPON_H
