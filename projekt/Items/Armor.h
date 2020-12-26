//
// Created by Nicolas Nguyen on 03/12/2020.
//

#ifndef PROJEKT_ARMOR_H
#define PROJEKT_ARMOR_H
#include "Item.h"

class Armor:public Item{
    int m_bonusArmor;

public:
    Armor(std::string name, int bonusArmor);
    int getBonusArmor();
    void printItem();
    void reduceArmor(int damage);
};


#endif //PROJEKT_ARMOR_H
