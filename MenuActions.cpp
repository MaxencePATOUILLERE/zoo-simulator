#include "MenuActions.h"
#include "zoo.h"
#include "string"
#include "zoo.h"
#include "./animal/tiger.h"
#include "./animal/eagle.h"
#include "./animal/chicken.h"
#include "./food/meat.h"
#include "./food/seed.h"
#include "./habitat/tiger_cage.h"
#include "./habitat/eagle_cage.h"
#include "./habitat/chicken_cage.h"

int MenuActions::buy_sell() {
    int buy_sell = 0;
    cout << "1. Do you want to buy ?\n2. Or sell ?" << endl;
    cin >> buy_sell;
    return buy_sell;
}

int MenuActions::choose_animal() {
    int animal = 0;
    cout << "1. A tiger?\n2. A eagle?\n3. A chicken?" << endl;
    cin >> animal;
    return animal;
}

bool MenuActions::is_male() {
    int genre = 0;
    while (1) {
        cout << "1. A male?\n2. A female?" << endl;
        cin >> genre;
        switch (genre) {
            case 1: {
                return true;
            }
            case 2: {
                return false;
            }
        }
    }
}

int MenuActions::choose_age_animal() {
    int seniority = 0;
    while (1) {
        cout << "1. Old?\n2. Middle age?\n3. Young?" << endl;
        cin >> seniority;
        switch (seniority) {
            case 1: {
                return 168;
            }
            case 2: {
                return 48;
            }
            case 3: {
                return 6;
            }
        }
    }
}

int MenuActions::choose_food() {
    int food = 0;
    cout << "1. Buy meat?\n2. Buy seed?" << endl;
    cin >> food;
    return food;
}

void MenuActions::createZoo() {
    string zoo_name;
    cout << "Choose a name for the zoo: ";
    cin >> zoo_name;
    Zoo *zoo = new Zoo(zoo_name, 80000);
    m_zoo = zoo;
    m_zoo->initFood();
}

void MenuActions::buyAnimal() {
    if (MenuActions::buy_sell() == 1) {
        switch (MenuActions::choose_animal()) {
            case 1: {
                string tiger_name = "";
                cout << "Choose a name: ";
                cin >> tiger_name;
                Tiger *tiger = new Tiger(is_male(), tiger_name, choose_age_animal());
                m_zoo->buyAnimal(tiger);
                break;
            }
            case 2: {
                string eagle_name = "";
                cout << "Choose a name: ";
                cin >> eagle_name;
                Eagle *eagloo = new Eagle(is_male(), eagle_name, choose_age_animal());
                m_zoo->buyAnimal(eagloo);
            }
                break;
            case 3: {
                string chicken_name = "";
                cout << "Choose a name: ";
                cin >> chicken_name;
                Chicken *poulette = new Chicken(is_male(), chicken_name, 6);
                m_zoo->buyAnimal(poulette);
            }
                break;
        }
    }
}

void MenuActions::buyFood() {
    int kilos = 0;
    cout << "How many kilos do you want to buy?" << endl;
    cin >> kilos;
    if (MenuActions::choose_food() == 1) {
        m_zoo->buyFood("meat", kilos);
    }else{
        m_zoo->buyFood("seed",kilos);
    }
}

void MenuActions::buyHabitat() {
    if (MenuActions::buy_sell() == 1) {
        cout << "Do you want to buy a habitat for which animal?" << endl;
        switch (MenuActions::choose_animal()) {
            case 1: {
                Tiger_cage *tiger_cage = new Tiger_cage("tiger_cage", 2000, 2);
                m_zoo->buyHabitat(tiger_cage);
                // afficher les sous en moins quand on buy un habitat
                break;
            }
            case 2: {
                Eagle_cage *eagle_cage = new Eagle_cage("eagle_cage", 2000, 4);
                m_zoo->buyHabitat(eagle_cage);
                break;
            }
            case 3: {
                Chicken_cage *chicken_cage = new Chicken_cage("chicken_cage", 300, 10);
                m_zoo->buyHabitat(chicken_cage);
                break;
            }
        }
    }
}

void MenuActions::chooseAction() {
    int action = 0;
    cout << "Choose an action:\n1. Buy/Sell animal\n2. Buy food\n3. Buy/Sell habitat\n4. Next turn" << endl;
    cin >> action;
    switch (action) {
        case 1:{
            MenuActions::buyAnimal();
            break;
        }
        case 2:{
            MenuActions::buyFood();
            break;
        }
        case 3:{
            MenuActions::buyHabitat();
            break;
        }
        case 4:{
            m_zoo.
        }
    }
}
