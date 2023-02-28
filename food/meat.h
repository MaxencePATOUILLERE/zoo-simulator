#ifndef MEAT_H
#define MEAT_H

#include "string"
#include "food.h"

using namespace std;

class Meat : public Food{
int m_kilos=0;
public:
    Meat(int kilos)
    :Food(kilos){m_kilos = kilos;};
    virtual int estimateBuyPrice();
    void setkilos(int kilos);

};
#endif