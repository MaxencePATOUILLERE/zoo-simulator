#ifndef CHICKEN_H
#define CHICKEN_H

#include "string"
#include "animal.h"

using namespace std;

class Chicken : public Animal{
public:
    Chicken(string name, int age_month)
    :Animal(name, age_month){};
    virtual int estimateBuyPrice();
};

#endif