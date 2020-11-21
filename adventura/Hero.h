//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_HERO_H
#define ADVENTURA_HERO_H
#include <iostream>
#include <vector>
#include "Spell.h"

enum heroType{warrior, mage};

class Hero {
    heroType m_type;
    std::string m_name;
    int m_health;
    int m_strength;
    int m_abilityPower;
    std::vector<Spell*> m_spells;
    Item* m_weapon;
    Item* m_armor;

public:
    Hero(heroType type,std::string name);
    heroType getType();
    std::string getName();
    int getHealth();
    int getStrength();
    int getAbilityPower();
    std::string getItemName(Item item);
    std::vector<Spell*> getSpells();
    int getWeaponStrength();
    int getArmor();
};


#endif //ADVENTURA_HERO_H
