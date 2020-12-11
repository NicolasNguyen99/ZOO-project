//
// Created by Nicolas Nguyen on 10/12/2020.
//

#ifndef PROJEKT_INVENTORY_H
#define PROJEKT_INVENTORY_H
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

typedef std::array<Weapon*,3> arrayOfWeapons;
typedef std::array<Armor*,3> arrayOfArmors;
typedef std::array<Potion*,5> arrayOfPotions;

struct Inventory {
private:
    arrayOfWeapons m_weapons;
    arrayOfArmors m_armors;
    arrayOfPotions m_potions;

public:
    Inventory();
    arrayOfWeapons getWeapon();
    Weapon* getWeapon(int index);
    void setWeapon(Weapon* weapon);
    void setWeapon(Weapon* weapon, int index);
    arrayOfArmors getArmor();
    Armor* getArmor(int index);
    void setArmor();
    void setArmor(int index);
    arrayOfPotions getPotion();
    Potion* getPotion(int index);
    void setPotion();
    void setPotion(int index);
};


#endif //PROJEKT_INVENTORY_H
