//
// Created by Nicolas Nguyen on 06/12/2020.
//

#ifndef PROJEKT_CHEST_H
#define PROJEKT_CHEST_H
#include "Items/Weapon.h"
#include "Items/Armor.h"
#include "Items/Potion.h"

class Chest {
    Weapon* m_weapon;
    Armor* m_armor;
    Potion* m_potion;
    Chest(Weapon* weapon, Armor* armor, Potion* potion);

public:
    Chest(Weapon* weapon);
    Chest(Armor* armor);
    Chest(Potion* potion);
    Weapon* getWeapon();
    Armor* getArmor();
    Potion* getPotion();
    ~Chest();
};


#endif //PROJEKT_CHEST_H
