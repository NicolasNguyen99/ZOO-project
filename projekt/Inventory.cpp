//
// Created by Nicolas Nguyen on 10/12/2020.
//

#include "Inventory.h"

Inventory::Inventory(){
    for(int i=0; i<m_weapons.size();i++){
        m_weapons.at(i) = nullptr;
    }
    for(int i=0; i<m_armors.size();i++){
        m_armors.at(i) = nullptr;
    }
    for(int i=0; i<m_potions.size();i++){
        m_potions.at(i) = nullptr;
    }
}

arrayOfWeapons Inventory::getWeapon(){
    return m_weapons;
}

Weapon* Inventory::getWeapon(int index){
    return m_weapons.at(index);
}

void Inventory::setWeapon(Weapon* weapon){
    int num = 0;
    bool isSetted = false;
    while(m_weapons.size() < num and !isSetted){
        if(m_weapons.at(num) == nullptr){
            m_weapons.at(num) = weapon;
            isSetted = true;
        } else {
            num++;
        }
    }
}

void Inventory::setWeapon(Weapon* weapon, int index){
    m_weapons.at(index) = weapon;
}

arrayOfArmors Inventory::getArmor(){
    return m_armors;
}

Armor* Inventory::getArmor(int index){
    return m_armors.at(index);
}

arrayOfPotions Inventory::getPotion(){
    return m_potions;
}

Potion* Inventory::getPotion(int index){
    return m_potions.at(index);
}
