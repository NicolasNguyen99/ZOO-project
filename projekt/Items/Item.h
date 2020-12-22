//
// Created by Nicolas Nguyen on 03/12/2020.
//

#ifndef PROJEKT_ITEM_H
#define PROJEKT_ITEM_H
#include <iostream>
#include <array>

class Item {
protected:
    std::string m_name;
    std::string m_type;

public:
    Item(std::string name, std::string type);
    virtual std::string getName();
    virtual std::string getType();
    virtual void printItem();
};


#endif //PROJEKT_ITEM_H
