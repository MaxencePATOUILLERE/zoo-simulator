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
    bool m_overcrowding = false;
    vector<Animal*>animals;
public:
    Habitat(string animal, string name, int price, int capacity):m_animal(animal), m_name(name), m_price(price), m_capacity(capacity){};
    virtual int estimateBuyPrice()=0;
    virtual int estimateSellPrice()=0;
    int getCapacity();
    void setOvercrowding();
    bool getOvercrowding();
    string getAnimal();
    void addAnimal(Animal* animal);
    int estimateTigerFood();
    int estimateEagleFood();
    int estimateChickenFood();
    void addDay();
    void giveFood();
    void checkHungryTiger();

    void isMatureTiger();

    void checkCoupleTiger();


    void checkGestation();

    void addTigrous();

    void checkTigerAge();

    void checkSickTiger();
};

#endif