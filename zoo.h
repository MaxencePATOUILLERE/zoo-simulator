#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <list>
#include <vector>
#include "./animal/animal.h"
#include "./food/food.h"
#include "./habitat/habitat.h"
#include "resources.h"
#include "tiger_cage.h"
#include "tiger.h"

using namespace std;

class Zoo{
    string m_name;
    double m_money;
    vector<Habitat*>habitats;
    vector<Food*>foods;
    Time *m_time = new Time(0,0);
    enum AnimalType {
        TIGER,
        EAGLE,
        CHICKEN
    };
public:
    Zoo(string name,int money)
    :m_name(name),m_money(money){};
    void addcage(Habitat *pCage);
    void buyAnimal(Animal* animal);
    void sellAnimal(Animal* animal);
    void buyFood(string foodname, int kilo);
    void buyHabitat(Habitat* habitat);
    void sellHabitat();
    bool canBuyAnimal(Animal* animal);
    bool canBuyHabitat(Habitat* habitat);
    int getMoney();
    bool checkHabitat(Animal* animal);
    vector<int> showSpecificHabitat(Animal* animal);
    void initFood();
    void addMonth();
    void checkAnimals();
    void addanimal(Animal *animal, int index);
    void suppr();
    int getNumberOf(AnimalType animal);
};

#endif