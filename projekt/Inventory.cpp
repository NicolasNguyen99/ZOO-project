//
// Created by Nicolas Nguyen on 10/12/2020.
//

#include "Inventory.h"

Inventory::Inventory(){
    for(auto &m_weapon : m_weapons){
        m_weapon = nullptr;
    }
    for(auto &m_armor : m_armors){
        m_armor = nullptr;
    }
    for(auto &m_potion : m_potions){
        m_potion = nullptr;
    }
}

ArrayOfWeapons Inventory::getWeapon(){
    return m_weapons;
}

Weapon* Inventory::getWeapon(int index){
    return m_weapons.at(index);
}

void Inventory::setWeapon(Weapon* weapon){
    int num = 0;
    bool isSetted = false;
    while(m_weapons.size() > num and !isSetted){
        if(m_weapons.at(num) == nullptr){
            m_weapons.at(num) = weapon;
            isSetted = true;
        } else {
            num++;
        }
    }
}

void Inventory::setArmor(Armor* armor){
    int num = 0;
    bool isSetted = false;
    while(m_armors.size() > num and !isSetted){
        if(m_armors.at(num) == nullptr){
            m_armors.at(num) = armor;
            isSetted = true;
        } else {
            num++;
        }
    }
}

void Inventory::setPotion(Potion* potion){
    int num = 0;
    bool isSetted = false;
    while(m_potions.size() > num and !isSetted){
        if(m_potions.at(num) == nullptr){
            m_potions.at(num) = potion;
            isSetted = true;
        } else {
            num++;
        }
    }
}

template <class Items>
bool Inventory::checkEmptyInv(Items items){
    bool isEmpty = true;
    for(auto item:items){
        if(item != nullptr){
            isEmpty = false;
        }
    }
    return isEmpty;
}

template <typename Items>
void Inventory::printItems(Items items){
    if(!checkEmptyInv(items)){
        int index = 1;
        for(auto item:items){
            if(item != nullptr){
                std::cout << index << ": ";
                item->printItem();
                index++;
            }
        }
    } else {
        std::cout << "Your inventory is empty\n";
    }
}

ArrayOfArmors Inventory::getArmor(){
    return m_armors;
}

Armor* Inventory::getArmor(int index){
    return m_armors.at(index);
}

ArrayOfPotions Inventory::getPotion(){
    return m_potions;
}

Potion* Inventory::getPotion(int index){
    return m_potions.at(index);
}

void Inventory::printWeapons(){
    printItems(m_weapons);
}

void Inventory::printArmors(){
    printItems(m_armors);
}

void Inventory::printPotions(){
    printItems(m_potions);
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