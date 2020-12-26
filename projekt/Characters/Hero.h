//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_HERO_H
#define PROJEKT_HERO_H
#include "Character.h"
#include "../Inventory.h"

class Hero:public Character{
    int m_level;
    int m_currentXp;
    int m_maxXp;
    int m_abilityPower;
    bool m_haveKey;
    Weapon* m_weapon;
    Armor* m_armor;
    Inventory* m_inventory;
    void levelCalc();
    void levelUp();

public:
    Hero(std::string name, std::string profession);
    int getAbilityPower();
    void printStats();
    void printInventory();
    void setWeapon(Weapon* weapon);
    void setArmor(Armor* armor);
    void pickWeapon(Weapon* weapon);
    void pickArmor(Armor* armor);
    void pickPotion(Potion* potion);
    void printEquipedWeapon();
    void printEquipedArmor();
    void printWeapons();
    void printArmors();

};


#endif //PROJEKT_HERO_H
