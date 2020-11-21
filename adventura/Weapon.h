//
// Created by Nicolas Nguyen on 21/11/2020.
//

#ifndef ADVENTURA_WEAPON_H
#define ADVENTURA_WEAPON_H
#include "Item.h"

class Weapon:public Item {
    int m_bonusStrength;
    int m_bonusAbilityPower;

public:
    Weapon(int bonusStrength, int bonusAbilityPower);
    int getBonusStrength();
    int getBonusAbilityPower();
};


#endif //ADVENTURA_WEAPON_H
