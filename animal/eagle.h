#ifndef EAGLE_H
#define EAGLE_H

#include "string"
#include "animal.h"

using namespace std;

class Eagle : public Animal{

public:
    Eagle(bool male, string name, int age_month)
    :Animal(male, name, age_month){};
    virtual int estimateBuyPrice();
};

#endif