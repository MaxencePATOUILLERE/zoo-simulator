#ifndef CHICKEN_H
#define CHICKEN_H

#include "string"
#include "animal.h"

using namespace std;

class Chicken : public Animal{
public:
    Chicken(bool male, string name, int age_month)
    :Animal(male, name, age_month, 5){};
    virtual int estimateBuyPrice();
};

#endif