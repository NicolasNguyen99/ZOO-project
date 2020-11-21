//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_ITEM_H
#define ADVENTURA_ITEM_H
#include <iostream>

enum typeOfItem{weapon=0,armor=1,spell=2,potion=3};

class Item {
protected:
    std::string m_name;
    typeOfItem m_type;

public:
    Item(std::string name, typeOfItem type);
    std::string getName();
    typeOfItem getType();
};


#endif //ADVENTURA_ITEM_H
