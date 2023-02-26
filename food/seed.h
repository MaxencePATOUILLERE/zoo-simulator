#ifndef SEED_H
#define SEED_H

#include "string"
#include "food.h"

using namespace std;

class Seed : public Food{
float m_kilos=0;
public:
    Seed(int kilos)
    :Food(kilos){m_kilos = kilos;};
    virtual int estimateBuyPrice();
};

#endif