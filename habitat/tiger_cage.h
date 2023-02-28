#ifndef TIGER_CAGE_H
#define TIGER_CAGE_H

#include "string"
#include "habitat.h"

using namespace std;

class Tiger_cage : public Habitat{
public:
    Tiger_cage(string name, int price, int capacity)
    :Habitat("tiger", name, price, capacity){};
    virtual int estimateBuyPrice();
    virtual int estimateSellPrice();
};

#endif