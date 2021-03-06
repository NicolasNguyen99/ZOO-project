//
// Created by Nicolas Nguyen on 02/12/2020.
//

#ifndef PROJEKT_HERO_H
#define PROJEKT_HERO_H
#include "Character.h"
#include "../Chest.h"
#include "../Inventory.h"

class Hero:public Character{
    int m_level;
    int m_currentXp;
    int m_maxXp;
    int m_abilityPower;
    bool m_haveKey;
    Weapon* m_weapon;
    Armor* m_armor;
    Inventory* m_inventory;
    void levelCalc();
    void levelUp();

    template <class Item>
    void printEquipedItem(Item item){
        if(item != nullptr){
            item->printItem();
        } else {
            std::cout << " -No equipped item";
        }
    }

    int drinkPotion(int index);
    void heal(int amount);

public:
    Hero(std::string name, std::string profession);
    int getAbilityPower();
    void printStats();
    void printInventory();
    void setWeapon(Weapon* weapon);
    void setArmor(Armor* armor);
    void printEquipedWeapon();
    void printEquipedArmor();
    void printWeapons();
    void printArmors();
    void takeDamage(int damage);
    void addXp(int xp);
    int equipWeapon(int index);
    int equipArmor(int index);
    void addItem(Chest* chest);
    void drinkPotionMenu();
    void weaponChangeMenu();
    void armorChangeMenu();
    void dropItemMenu();
    //provizorne
    int getInput();
};


#endif //PROJEKT_HERO_H
