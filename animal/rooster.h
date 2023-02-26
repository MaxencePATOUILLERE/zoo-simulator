#ifndef ROOSTER_H
#define ROOSTER_H

#include "string"
#include "animal.h"

using namespace std;

class Rooster : public Animal{

public:
    Rooster(string name, int age_month)
    :Animal(name, age_month){};
    virtual int estimateBuyPrice();
};

#endif