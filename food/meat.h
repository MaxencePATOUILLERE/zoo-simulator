#ifndef MEAT_H
#define MEAT_H

#include "string"
#include "food.h"

using namespace std;

class Meat : public Food{
public:
    Meat(int kilos):Food(kilos){};
};
#endif