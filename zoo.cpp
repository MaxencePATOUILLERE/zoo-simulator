#include "zoo.h"
#include "tiger.h"
#include "chicken.h"
#include "eagle.h"
#include "meat.h"
#include "seed.h"
#include <iostream>

using namespace std;

void Zoo::buyAnimal(Animal *animal) {
    int indexHabitat;
    bool good = false;
    if (checkHabitat(animal)) {
        if (canBuyAnimal(animal)) {
            vector<int> specificHabitat = showSpecificHabitat(animal);
            cout << "You can stock your animal in habitat number: ";
            for (int i = 0; i < specificHabitat.size(); i++) {
                cout << specificHabitat[i]<< ",";
            }
            while (!good) {
                cout << endl << "Choose the habitat for your animal" << endl;
                cin >> indexHabitat;
                for (int i = 0; i < specificHabitat.size(); i++) {
                    if (indexHabitat == specificHabitat[i]) {
                        good = true;
                        break;
                    }
                }
            }
            habitats[indexHabitat]->addAnimal(animal);
            m_money -= animal->estimateBuyPrice();
            cout << "You have: " << getMoney() << "money" << endl;
            cout << "Your animal name's: " << animal->getName() << ", he's old is: " << animal->getAge() << "and has: " << animal->getChanceSick() << "% to get sick" << endl;
            return;
        } else {
            cout << "You don't have enough money" << endl;
            return;
        }
    }
    cout << "You don't have the necessary habitat for this animal" << endl;

}

void Zoo::sellAnimal(Animal *animal) {

}

void Zoo::buyFood(Food *food) {

}

void Zoo::buyHabitat(Habitat *habitat) {
    if (canBuyHabitat(habitat)) {
        habitats.push_back(habitat);
        m_money -= habitat->estimateBuyPrice();
        cout << "You have: " << getMoney() << "money" << endl;
        cout << "The habitat has: " << habitat->getCapacity() << "capacity with 50% chance of loss due to overcrowding"
             << endl;
        return;
    }
    cout << "You don't have enough money" << endl;
};

void Zoo::sellHabitat(Habitat *habitat) {
}

bool Zoo::canBuyAnimal(Animal *animal) {
    if (m_money > animal->estimateBuyPrice()) {
        return true;
    }
    return false;
}

int Zoo::getMoney() {
    return m_money;
}

bool Zoo::canBuyHabitat(Habitat *habitat) {
    if (m_money > habitat->estimateBuyPrice()) {
        return true;
    }
    return false;
}

bool Zoo::checkHabitat(Animal *animal) {
    if (habitats.size() == 0) {
        return false;
    }
    for (int i = 0; i < habitats.size(); i++) {
        if (habitats[i]->getAnimal() == "tiger" && dynamic_cast<Tiger *>(animal) != nullptr) {
            return true;
        }
        if (habitats[i]->getAnimal() == "eagle" && dynamic_cast<Eagle *>(animal) != nullptr) {
            return true;
        }
        if (habitats[i]->getAnimal() == "chicken" && dynamic_cast<Chicken *>(animal) != nullptr) {
            return true;
        }
    }
    return false;
}

vector<int> Zoo::showSpecificHabitat(Animal *animal) {
    vector<int> specificHabitat;
    for (int i = 0; i < habitats.size(); i++) {
        if (habitats[i]->getAnimal() == "tiger" && dynamic_cast<Tiger *>(animal) != nullptr) {
            specificHabitat.push_back(i);
        }
        if (habitats[i]->getAnimal() == "eagle" && dynamic_cast<Eagle *>(animal) != nullptr) {
            specificHabitat.push_back(i);
        }
        if (habitats[i]->getAnimal() == "chicken" && dynamic_cast<Chicken *>(animal) != nullptr) {
            specificHabitat.push_back(i);
        }
    }
    return specificHabitat;
}

bool Zoo::haveFood(string foodname) {
    if (foods.empty()){
        return false;
    }
    if ((dynamic_cast<Meat *>(foods[0])!= nullptr && foodname=="meat")||(dynamic_cast<Seed *>(foods[0])!= nullptr && foodname=="seed")){
        return true;
    }else if (foods.size()==2 && (dynamic_cast<Meat *>(foods[1])!= nullptr && foodname=="meat")||(dynamic_cast<Seed *>(foods[1])!= nullptr && foodname=="seed")) {
        return true;
    }else{
        return false;
    }
}
