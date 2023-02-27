#ifndef RESOURCES_H
#define RESOURCES_H

#include "string"
#include "./animal/animal.h"

using namespace std;

class Resources{
    int m_month;
    int m_price;
public:
    virtual bool canBuy(Animal* animal);
};

#endif