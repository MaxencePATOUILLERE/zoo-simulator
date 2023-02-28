#ifndef CHICKEN_CAGE_H
#define CHICKEN_CAGE_H

#include "string"
#include "habitat.h"

using namespace std;

class Chicken_cage : public Habitat{
public:
    Chicken_cage(string name, int price, int capacity)
    :Habitat("chicken",name, price, capacity){};
    virtual int estimateBuyPrice();
    virtual int estimateSellPrice();
};

#endif