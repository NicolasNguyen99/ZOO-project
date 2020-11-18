//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_INVENTORY_H
#define ADVENTURA_INVENTORY_H
#include <array>
#include "Item.h"
const int sizeOfInventory = 5;

class Inventory {
    std::array<Item*, sizeOfInventory> m_inventory;

public:
    Inventory();
};


#endif //ADVENTURA_INVENTORY_H
