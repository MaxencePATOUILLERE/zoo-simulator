#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <list>
#include <vector>
#include "./animal/animal.h"
#include "./food/food.h"
#include "./habitat/habitat.h"
#include "resources.h"
using namespace std;

class Zoo{
    string m_name;
    double m_money;
    vector<Habitat*>habitats;
    vector<Food*>foods;
    Time *m_time = new Time(0,0);
public:
    Zoo(string name,int money)
    :m_name(name),m_money(money){};
    void buyAnimal(Animal* animal);
    void sellAnimal(Animal* animal);
    void buyFood(string foodname, int kilo);
    void buyHabitat(Habitat* habitat);
    void sellHabitat(Habitat* habitat);
    bool canBuyAnimal(Animal* animal);
    bool canBuyHabitat(Habitat* habitat);
    int getMoney();
    bool checkHabitat(Animal* animal);
    vector<int> showSpecificHabitat(Animal* animal);
    void initFood();
    void addMonth();
    void checkAnimals();
    void checkTiger(int indexHabitat);
    void checkEagle(int indexHabitat);
    void checkChicken(int indexHabitat);
};

#endif