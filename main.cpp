#include <iostream>
#include <string>
#include "zoo.h"
#include "./animal/tiger.h"
#include "./animal/eagle.h"
#include "./animal/chicken.h"
#include "./food/meat.h"
#include "./food/seed.h"
#include "./habitat/tiger_cage.h"
#include "./habitat/eagle_cage.h"
#include "./habitat/chicken_cage.h"

using namespace std;

int buy_sell() {
    int buy_sell = 0;
    cout << "1. Do you want to buy ?\n2. Or sell ?" << endl;
    cin >> buy_sell;
    return buy_sell;
}

int choose_animal() {
    int animal = 0;
    cout << "1. A tiger?\n2. A eagle?\n3. A chicken?" << endl;
    cin >> animal;
    return animal;
}

bool is_male() {
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

int choose_age_animal() {
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

int choose_food() {
    int food = 0;
    cout << "1. Buy meat?\n2. Buy seed?" << endl;
    cin >> food;
    return food;
}

int main() {
    string zoo_name;
    cout << "Choose a name for the zoo: ";
    cin >> zoo_name;
    Zoo *zoo = new Zoo(zoo_name, 80000);

    while (1) {
        int action = 0;
        cout << "Choose an action:\n1. Buy/Sell animal\n2. Buy food\n3. Buy/Sell habitat\n4. Next turn" << endl;
        cin >> action;
        switch (action) {
            case 1: {
                if (buy_sell() == 1) {
                    switch (choose_animal()) {
                        case 1: {
                            string tiger_name = "";
                            cout << "Choose a name: ";
                            cin >> tiger_name;
                            Tiger *tiger = new Tiger(is_male(), tiger_name, choose_age_animal());
                            zoo->buyAnimal(tiger);
                            break;
                        }
                        case 2: {
                            string eagle_name = "";
                            cout << "Choose a name: ";
                            cin >> eagle_name;
                            Eagle *eagloo = new Eagle(is_male(), eagle_name, choose_age_animal());
                            zoo->buyAnimal(eagloo);
                        }
                            break;
                        case 3: {
                            string chicken_name = "";
                            cout << "Choose a name: ";
                            cin >> chicken_name;
                            Chicken *poulette = new Chicken(is_male(), chicken_name, 6);
                            zoo->buyAnimal(poulette);
                        }
                            break;
                    }
                } else {
                    // Je verrai bien un truc du genre : ici on affiche tous les animaux qu'il y a dans le zoo
                    // ici on récupère un int (maybe via une méthode "zoo->get_animal_to_sell") correspondant à l'animal que l'on veut retirer de la slice
                    // on stock le résultat de la méthode dans une variable
                    // ici on appelle une méthode qui va supprimer l'animal choisit dans la slice (maybe "zoo->sellAnimal(zoo->get_animal_to_sell(variable))")
                    // si tu vois autre chose, n'hésite pas à share
                    // faire pareil pour l'argent gagné
                }
                break;
            }
            case 2: {
                int kilos = 0;
                cout << "How many kilos do you want to buy?" << endl;
                cin >> kilos;
                if (choose_food() == 1) {
                    Meat *meat = new Meat(kilos);
                    zoo->buyFood(meat);
                    // afficher les sous en moins quand on buy de la nourriture
                } else {
                    Seed *seed = new Seed(kilos);
                    zoo->buyFood(seed);
                }
            }
            case 3: {
                if (buy_sell() == 1) {
                    cout << "Do you want to buy a habitat for which animal?" << endl;
                    switch (choose_animal()) {
                        case 1: {
                            Tiger_cage *tiger_cage = new Tiger_cage("tiger_cage", 2000, 2);
                            zoo->buyHabitat(tiger_cage);
                            // afficher les sous en moins quand on buy un habitat
                            break;
                        }
                        case 2: {
                            Eagle_cage *eagle_cage = new Eagle_cage("eagle_cage", 2000, 4);
                            zoo->buyHabitat(eagle_cage);
                            break;
                        }
                        case 3: {
                            Chicken_cage *chicken_cage = new Chicken_cage("chicken_cage", 300, 10);
                            zoo->buyHabitat(chicken_cage);
                            break;
                        }
                    }
                } else {
                    // pareil que le pavé plus haut pour la vente d'animal
                    //zoo->sellHabitat(zoo->get_habitat_to_sell);
                }
            }
            case 4:
                continue;
        }

    }

    return 0;
}