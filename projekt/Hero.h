//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_HERO_H
#define PROJEKT_HERO_H
#include "Character.h"
#include "Inventory.h"

class Hero:public Character{
    int m_abilityPower;
    bool m_haveKey;
    Weapon* m_weapon;
    Armor* m_armor;
    Inventory* m_inventory;

public:
    Hero(std::string name, std::string profession);
    int getAbilityPower();
    void printStats();
    void printInventory();
    void setWeapon(Weapon* weapon);
    void setArmor(Armor* armor);
    void pickWeapon(Weapon* weapon);
    void pickArmor(Armor* armor);

};


#endif //PROJEKT_HERO_H
