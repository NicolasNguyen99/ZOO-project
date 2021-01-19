//
// Created by Nicolas Nguyen on 10/12/2020.
//

#ifndef PROJEKT_INVENTORY_H
#define PROJEKT_INVENTORY_H
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

typedef std::array<Weapon*,3> ArrayOfWeapons;
typedef std::array<Armor*,3> ArrayOfArmors;
typedef std::array<Potion*,5> ArrayOfPotions;

//template <class Items> class Inventory{
class Inventory {
private:
    ArrayOfWeapons m_weapons;
    ArrayOfArmors m_armors;
    ArrayOfPotions m_potions;

    template <class ArrayItems, class Item>
    void addItem(ArrayItems &arrayItems, Item item){
        int num = 0;
        bool isSetted = false;
        while(arrayItems.size() > num and !isSetted){
            if(arrayItems.at(num) == nullptr){
                arrayItems.at(num) = item;
                isSetted = true;
            } else {
                num++;
            }
        }
    }

    template <class Items>
    void printItems(Items items){
        if(!checkEmptyInv<>(items)){
            int index = 1;
            for(auto item:items){
                if(item != nullptr){
                    std::cout << " " << index << ": \n";
                    item->printItem();
                    index++;
                }
            }
        } else {
            std::cout << "Your inventory is empty\n";
        }
    }

    template <class Items>
    void suspendItem(Items &items, int index){
        if(index > 0 and index <= items.size()){
            items.at(index-1)= nullptr;
        } else {
            std::cout << "Mimo rozsah\n";
        }
    }

    template <class Items>
    void rearangeItems(Items &items){
        Items tem;
        for(auto &item:tem){
            item = nullptr;
        }
        int index = 0;
        for(auto item:items){
            if(item != nullptr){
                tem.at(index) = item;
                index++;
            }
        }
        items = tem;
    }

    template <class Items>
    void discardItem(Items &items, int index){
        if(index > 0 and index <= items.size()){
            delete items.at(index-1);
            items.at(index-1) = nullptr;
            rearangeItems<>(items);
        } else {
            std::cout << "Mimo rozsah\n";
        }
    }

    char convertCharToSmall(char letter);
    int getInput();

public:
    Inventory();
    void addWeapon(Weapon* weapon);
    void addArmor(Armor* armor);
    void addPotion(Potion* potion);
    Weapon* getWeapon(int index);
    Armor* getArmor(int index);
    Potion* getPotion(int index);
    void printInventory();
    void printWeapons();
    void printArmors();
    void printPotions();
    void suspendWeapon(int index);
    void suspendArmor(int index);
    void dropItemMenu();
    void discardPotion(int index);
    ArrayOfPotions getPotions();
    ArrayOfWeapons getWeapons();
    ArrayOfArmors getArmors();

    template <class Items>
    bool checkEmptyInv(Items items){
        bool isEmpty = true;
        for(auto item:items){
            if(item != nullptr){
                isEmpty = false;
            }
        }
        return isEmpty;
    }
};

#endif //PROJEKT_INVENTORY_H
