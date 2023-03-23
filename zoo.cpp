#include <stdlib.h>
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
                cout << specificHabitat[i] << ",";
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
            cout << "Your animal name's: " << animal->getName() << ", he's old is: " << animal->getAge() << "and has: "
                 << animal->getChanceSick() << "% to get sick" << endl;
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

void Zoo::buyFood(string foodname, int kilos) {
    if (foodname == "meat") {
        if (getMoney() >= 5 * kilos) {
            cout << kilos << endl;
            foods[0]->addKilos(kilos);
            m_money -= 5 * kilos;
            cout << "You have: " << getMoney() << "money" << endl;
            cout << "You have: " << foods[0]->getKilos() << " kg of meat now" << endl;
        } else {
            cout << "You have don't have enough money" << endl;
        }
    }
    if (foodname == "seed") {
        if (getMoney() >= 2.5 * kilos) {
            cout << kilos << endl;
            foods[1]->addKilos(kilos);
            m_money -= 2.5 * kilos;
            cout << "You have: " << getMoney() << " money" << endl;
            cout << "You have: " << foods[1]->getKilos() << " kg of seed now" << endl;
        } else {
            cout << "You have don't have enough money" << endl;
        }
    }
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


void Zoo::initFood() {
    Meat *meat = new Meat(0);
    Seed *seed = new Seed(0);
    foods.push_back(meat);
    foods.push_back(seed);
}

void Zoo::addMonth() {
    for (int i = 1; i < 31; i++) {
        m_time->setDay(1);
        checkAnimals();
    }
    /*
    int visitor_number;
     a refaire
    if (m_time->getMonth()==5 || m_time->getMonth()==6 || m_time->getMonth()==7 || m_time->getMonth()==8 || m_time->getMonth()==9){
        visitor_number = rand() % 500 + 900;
    }else{
        visitor_number = rand() % 200 + 400;
    }
    m_money+= visitor_number * 60;
     */
}

void Zoo::checkAnimals() {
    for (int i = 0; i < habitats.size(); i++) {
        habitats[i]->addDay();
        if (habitats[i]->getAnimal() == "tiger") {
            if (foods[0]->getKilos() >= habitats[i]->estimateFood()) {
                habitats[i]->giveFood();
                foods[0]->removeKilos(habitats[i]->estimateFood());
            } else {
                habitats[i]->checkHungry();
            }
        } else {
            if (foods[1]->getKilos() >= habitats[i]->estimateFood()) {
                habitats[i]->giveFood();
                foods[1]->removeKilos(habitats[i]->estimateFood());
            } else {
                habitats[i]->checkHungry();
            }
            habitats[i]->checkCouple();
            habitats[i]->checkGestation();
            habitats[i]->isMature();
            habitats[i]->checkAge();
            habitats[i]->checkSick();
        }
    }
}

void Zoo::addcage(Habitat *pCage) {
    habitats.push_back(pCage);
}

void Zoo::addanimal(Animal *animal, int index) {
    habitats[0]->addAnimal(animal);
}
