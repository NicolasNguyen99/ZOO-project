//
// Created by Nicolas Nguyen on 03/12/2020.
//

#ifndef PROJEKT_POTION_H
#define PROJEKT_POTION_H
#include "Item.h"

class Potion:public Item{
    int m_healAmount;

public:
    Potion(std::string name, std::string type, int healAmount);
    int getHealAmount();
};


#endif //PROJEKT_POTION_H
