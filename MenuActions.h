#ifndef MAIN_CPP_MENUACTIONS_H
#define MAIN_CPP_MENUACTIONS_H
#include "iostream"
#include "zoo.h"
using namespace std;

class MenuActions {
    Zoo* m_zoo;
    int buy_sell();
    int choose_animal();
    bool is_male();
    int choose_age_animal();
    int choose_food();

    void buyAnimal();
    void buyFood();
    void buyHabitat();
public:
    void createZoo();
    void chooseAction();
    //void continue();
};

#endif //MAIN_CPP_MENUACTIONS_H
