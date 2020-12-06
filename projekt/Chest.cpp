//
// Created by Nicolas Nguyen on 06/12/2020.
//

#include "Chest.h"

Chest::Chest(Weapon* weapon, Armor* armor, Potion* potion){
    m_weapon = weapon;
    m_armor = armor;
    m_potion = potion;
}

Chest::Chest(Weapon* weapon):Chest(weapon, nullptr, nullptr){}

Chest::Chest(Armor* armor):Chest(nullptr, armor, nullptr){}

Chest::Chest(Potion* potion):Chest(nullptr, nullptr, potion){}

Weapon* Chest::getWeapon(){
    return m_weapon;
}

Armor* Chest::getArmor(){
    return m_armor;
}

Potion* Chest::getPotion(){
    return m_potion;
}
