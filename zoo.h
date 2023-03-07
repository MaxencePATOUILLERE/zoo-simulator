#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <list>
#include <vector>
#include "./animal/animal.h"
#include "./food/food.h"
#include "./habitat/habitat.h"

using namespace std;

class Zoo{
    string m_name;
    double m_money;
    vector<Habitat*>habitats;
    vector<Food*>foods;
public:
    Zoo(string name,int money):m_name(name),m_money(money){};
    void buyAnimal(Animal* animal);
    void sellAnimal(Animal* animal);
    void buyFood(string foodname, int kilo);
    bool haveFood(string foodname);
    void buyHabitat(Habitat* habitat);
    void sellHabitat(Habitat* habitat);
    bool canBuyAnimal(Animal* animal);
    bool canBuyHabitat(Habitat* habitat);
    int getMoney();
    bool checkHabitat(Animal* animal);
    vector<int> showSpecificHabitat(Animal* animal);
    void initFood();
};

#endif