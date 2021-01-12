//
// Created by Nicolas Nguyen on 10/12/2020.
//

#include "Inventory.h"

Inventory::Inventory(){
    for(auto &m_weapon:m_weapons){
        m_weapon = nullptr;
    }
    for(auto &m_armor:m_armors){
        m_armor = nullptr;
    }
    for(auto &m_potion:m_potions){
        m_potion = nullptr;
    }
}

Weapon* Inventory::getWeapon(int index){
    Weapon* weapon;
    if(index > 0 and index <= m_weapons.size()){
        weapon = m_weapons.at(index-1);
    } else {
        weapon = nullptr;
    }
    return weapon;
}

Armor* Inventory::getArmor(int index){
    return m_armors.at(index);
}

Potion* Inventory::getPotion(int index){
    return m_potions.at(index);
}

void Inventory::addWeapon(Weapon* weapon){
    addItem<>(m_weapons, weapon);
}

void Inventory::addArmor(Armor* armor){
    addItem<>(m_armors, armor);
}

void Inventory::addPotion(Potion* potion){
    addItem<>(m_potions, potion);
}

void Inventory::printWeapons(){
    printItems<>(m_weapons);
}

void Inventory::printArmors(){
    printItems<>(m_armors);
}

void Inventory::printPotions(){
    printItems<>(m_potions);
}

void Inventory::printInventory(){
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Weapons: " << std::endl;
    printWeapons();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Armors: " << std::endl;
    printArmors();
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Potions: " << std::endl;
    printPotions();
    std::cout << "--------------------------------" << std::endl;
}

void Inventory::removeWeapon(int index){
    if(index > 0 and index <= m_weapons.size()){
        m_weapons.at(index-1) = nullptr;
    }
}