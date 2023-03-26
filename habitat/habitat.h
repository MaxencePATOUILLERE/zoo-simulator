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
    string getAnimal();
    void addAnimal(Animal* animal);
    double estimateFood();
    void addDay();
    void giveFood();
    void checkHungry();
    void isMature();
    void checkCouple();
    void checkGestation();
    void addTigrous();
    void checkAge();
    void checkSick();
    void addEaglouglou();
    void addKfc();
    vector <int> showListAnimal();
    int estimateSellPriceByIndex(int index);
    void removeAnimal(int i);
    void sell();
    ~Habitat();

};

#endif