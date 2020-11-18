//
// Created by Nicolas Nguyen on 18/11/2020.
//

#include "Inventory.h"

Inventory::Inventory(){
    for(int i = 0; i < sizeOfInventory; i++){
        m_inventory.at(i) = nullptr;
    }
}