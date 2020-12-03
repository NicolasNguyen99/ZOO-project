//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_HERO_H
#define PROJEKT_HERO_H
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

class Hero:public Character{
    int m_abilityPower;
    bool m_haveKey;
    Weapon* m_weapon;
    Armor* m_armor;
    std::array<Weapon*,3> m_invWeapons;
    std::array<Armor*,3> m_invArmors;
    std::array<Potion*,5> m_invPotions;

public:
    Hero(std::string name, int health, int strength);
    int getAbilityPower();
};


#endif //PROJEKT_HERO_H
