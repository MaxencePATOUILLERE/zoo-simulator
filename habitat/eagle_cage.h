#ifndef EAGLE_CAGE_H
#define EAGLE_CAGE_H

#include "string"
#include "habitat.h"

using namespace std;

class Eagle_cage : public Habitat{
public:
    Eagle_cage(string name, int price, int capacity)
    :Habitat("eagle", name, price, capacity){};
    virtual int estimateBuyPrice();
    virtual int estimateSellPrice();
};

#endif