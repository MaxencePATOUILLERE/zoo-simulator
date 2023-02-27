#ifndef HABITAT_H
#define HABITAT_H

#include <string>
#include <vector>
#include "animal.h"

using namespace std;

class Habitat{
    string m_animal;
    string m_name;
    int m_price=0;
    int m_capacity=0;
    vector<Animal*>animals;
public:
    Habitat(string animal, string name, int price, int capacity):m_animal(animal), m_name(name), m_price(price), m_capacity(capacity){};
    virtual int estimateBuyPrice()=0;
    virtual int estimateSellPrice()=0;
    int getCapacity();
};

#endif