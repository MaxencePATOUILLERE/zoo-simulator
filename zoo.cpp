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
    int indexHabitat;
    bool good = false;
    if (checkHabitat(animal)) {
        vector<int> specificHabitat = showSpecificHabitat(animal);
        cout << "You can sell an animal in habitat number: ";
        for (int i = 0; i < specificHabitat.size(); i++) {
            cout << specificHabitat[i] << ",";
            while (!good) {
                cout << endl << "Choose the habitat for your animal you are selling" << endl;
                cin >> indexHabitat;
                for (int i = 0; i < specificHabitat.size(); i++) {
                    if (indexHabitat == specificHabitat[i]) {
                        good = true;
                        break;
                    }
                }
            }
        }
        int indexAnimal;
        good = false;
        vector<int> specificAnimal = habitats[indexHabitat]->showListAnimal();
        while (!good) {
            cout << endl << "Choose the animal :";
            for (int i = 0 ; i < specificAnimal.size(); i++){
                cout << specificAnimal[i] << ",";
            }
            cout << endl;
            cin >> indexAnimal;
            for (int i = 0; i < specificAnimal.size(); i++) {
                if (indexAnimal == specificAnimal[i]) {
                    good = true;
                    break;
                }
            }
        }
        m_money += habitats[indexHabitat]->estimateSellPriceByIndex(indexAnimal);
        habitats[indexHabitat]->removeAnimal(indexAnimal);
        cout << "You have: " << getMoney() << "money" << endl;
    }
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

void Zoo::sellHabitat() {
    vector<int> index;
    bool good;
    int choice;
    if (habitats.size() ==0){
        cout << "You don't have habitat"<<endl;
        return;
    }
    cout << "Which habitat you want to sell (if you sell an habitat with animals you will loose them) : ";
    for (int i = 0; i < habitats.size();i++) {
        cout << i << ",";
    }
    while (!good) {
        cout << endl << "Choose the habitat for your animal you are selling" << endl;
        cin >> choice;
        for (int i = 0; i < habitats.size(); i++) {
            if (choice == i) {
                good = true;
                break;
            }
        }
    }
    m_money+=habitats[choice]->estimateBuyPrice()/4;
    habitats[choice]->sell();
    habitats.erase(habitats.begin() + choice);
    cout << "You have: " << getMoney() << "money" << endl;
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
    double total;
    for (int i = 1; i < 31; i++) {
        m_time->setDay(1);
        checkAnimals();
        double visitor_number;
        if (m_time->getMonth()==5 || m_time->getMonth()==6 || m_time->getMonth()==7 || m_time->getMonth()==8 || m_time->getMonth()==9){
            visitor_number = ((getNumberOf(TIGER) * 30 + getNumberOf(EAGLE) * 15 + getNumberOf(CHICKEN) * 2)) / 31;
        }else{
            visitor_number = ((getNumberOf(TIGER) * 5 + getNumberOf(EAGLE) * 7 + getNumberOf(CHICKEN) * 0.5)) / 31;
        }
        total += visitor_number;
        m_money+= visitor_number * 60;

    }
    cout << "You win " << total * 60 << " dollars during the month"<<endl;
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
    habitats[index]->addAnimal(animal);
}

void Zoo::suppr() {
    delete this;
}

int Zoo::getNumberOf(AnimalType animal) {
    int animals;
    switch (animal){
        case TIGER:{
            for (int i = 0; i < habitats.size(); i++){
                if (habitats[i]->getAnimal()=="tiger"){
                    animals += habitats[i]->showListAnimal().size();
                }
            }
            break;
        }
        case EAGLE:{
            for (int i = 0; i < habitats.size(); i++){
                if (habitats[i]->getAnimal()=="eagle"){
                    animals += habitats[i]->showListAnimal().size();
                }
            }
            break;
        }
        case CHICKEN:{
            for (int i = 0; i < habitats.size(); i++){
                if (habitats[i]->getAnimal()=="chicken"){
                    animals += habitats[i]->showListAnimal().size();
                }
            }
            break;
        }
    }
    return animals;
}
