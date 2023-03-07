#ifndef SEED_H
#define SEED_H

#include "string"
#include "food.h"

using namespace std;

class Seed : public Food{
public:
    Seed(int kilos):Food(kilos){};
};

#endif