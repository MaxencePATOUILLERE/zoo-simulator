#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <vector>
#include "./animal/animal.h"
#include "./food/food.h"
#include "./habitat/habitat.h"

using namespace std;

class Zoo{
    string m_name;
    int m_money;
    vector<Habitat*>habitats;
public:
    Zoo(string name,int money):m_name(name),m_money(money){};
    void buyAnimal(Animal* animal);
    void sellAnimal(Animal* animal);
    void buyFood(Food* food);
    void buyHabitat(Habitat* habitat);
    void sellHabitat(Habitat* habitat);
    bool canBuy(Animal* animal);
    int getMoney();
};

#endif