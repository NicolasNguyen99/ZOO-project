//
// Created by Nicolas Nguyen on 18/11/2020.
//

#ifndef ADVENTURA_ITEM_H
#define ADVENTURA_ITEM_H
#include <iostream>

enum typeOfItem{weapon=0,armor=1,potion=2};

class Item {
    std::string m_nazev;
    std::string m_type;

public:
    Item();
    std::string getNazev();
    std::string getType();
};


#endif //ADVENTURA_ITEM_H
