//
// Created by Nicolas Nguyen on 10/12/2020.
//

#ifndef PROJEKT_INVENTORY_H
#define PROJEKT_INVENTORY_H
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

//zvetsit nazvy typedefu
typedef std::array<Weapon*,3> arrayOfWeapons;
typedef std::array<Armor*,3> arrayOfArmors;
typedef std::array<Potion*,5> arrayOfPotions;

//template <class Items> class Inventory {
class Inventory {
private:
    arrayOfWeapons m_weapons;
    arrayOfArmors m_armors;
    arrayOfPotions m_potions;

public:
    Inventory();
    arrayOfWeapons getWeapon();
    Weapon* getWeapon(int index);
    void setWeapon(Weapon* weapon);
    void setArmor(Armor* armor);
    void setPotion(Potion* potion);
    arrayOfArmors getArmor();
    Armor* getArmor(int index);
    void setArmor();
    void setArmor(int index);
    arrayOfPotions getPotion();
    Potion* getPotion(int index);
    void setPotion(int index);
    void printInventory();
    template <class Items>
    void printItems(Items items);
};


//
//template <class Items>
//void Inventory<Items>::printItems(Items items){
//    int index = 1;
//    for(auto item:items){
//        if(item != nullptr){
//            std::cout << index << ": " + item->getName() << std::endl;
//            std::cout << "  -Type: " + item->getType() << std::endl;
////            std::cout << index << ": " << item->getBonusStrength() << std::endl;
//            index++;
//        }
//    }
//}

#endif //PROJEKT_INVENTORY_H
