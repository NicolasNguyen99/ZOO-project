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
    Armor* armor;
    if(index > 0 and index <= m_armors.size()){
        armor = m_armors.at(index-1);
    } else {
        armor = nullptr;
    }
    return armor;
}

Potion* Inventory::getPotion(int index){
    Potion* potion;
    if(index > 0 and index <= m_potions.size()){
        potion = m_potions.at(index-1);
    } else {
        potion = nullptr;
    }
    return potion;
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
    std::cout << "Weapons: " << std::endl;
    printItems<>(m_weapons);
}

void Inventory::printArmors(){
    std::cout << "Armors: " << std::endl;
    printItems<>(m_armors);
}

void Inventory::printPotions(){
    std::cout << "Potions: " << std::endl;
    printItems<>(m_potions);
}

void Inventory::printInventory(){
    std::cout << "Inventory: \n";
    std::cout << "--------------------------------" << std::endl;
    printWeapons();
    std::cout << "--------------------------------" << std::endl;
    printArmors();
    std::cout << "--------------------------------" << std::endl;
    printPotions();
    std::cout << "--------------------------------" << std::endl;
}

void Inventory::suspendWeapon(int index){
    suspendItem<>(m_weapons, index);
}

void Inventory::suspendArmor(int index){
    suspendItem<>(m_armors, index);
}

void Inventory::removePotion(int index){
    suspendItem(m_potions, index);
    m_potions.at(index) = nullptr;
}