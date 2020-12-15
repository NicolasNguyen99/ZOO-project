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

arrayOfWeapons Inventory::getWeapon(){
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

template <typename Items>
void Inventory::printItems(Items items){
    int index = 1;
    for(auto item:items){
        if(item != nullptr){
            std::cout << index << ": " + item->getName() << std::endl;
            std::cout << "  -Type: " + item->getType() << std::endl;
//            std::cout << index << ": " << item->getBonusStrength() << std::endl;
            index++;
        }
    }
}

void Inventory::printInventory(){
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Weapons: " << std::endl;
    printItems(m_weapons);
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Armors: " << std::endl;
    printItems(m_armors);
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Potions: " << std::endl;
    printItems(m_potions);
    std::cout << "--------------------------------" << std::endl;
}