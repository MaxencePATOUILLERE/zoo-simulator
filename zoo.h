#ifndef ZOO_H
#define ZOO_H

#include <string>
#include "./animal/animal.h"
#include "./food/food.h"
#include "./habitat/habitat.h"

using namespace std;

class Zoo{
    string m_name;
public:
    Zoo(string name):m_name(name){};
    void buyAnimal(Animal* animal);
    void sellAnimal(Animal* animal);
    void buyFood(Food* food);
    void buyHabitat(Habitat* habitat);
    void sellHabitat(Habitat* habitat);
};

#endif