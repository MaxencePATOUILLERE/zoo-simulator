#ifndef TIGER_H
#define TIGER_H

#include "animal.h"
#include "string"

using namespace std;

class Tiger : public Animal{
public:
    Tiger(bool male, string name, int age_month)
    :Animal(male, name, age_month){};
    virtual int estimateBuyPrice();
};

#endif