#include "habitat.h"
#include "iostream"
#include <stdlib.h>
#include "tiger.h"
#include "chicken.h"
#include "eagle.h"
#include "cmath"

int Habitat::getCapacity() {
    return m_capacity;
}

string Habitat::getAnimal() {
    return m_animal;
}

void Habitat::addAnimal(Animal *animal) {
    animals.push_back(animal);
}

double Habitat::estimateFood() {
    double kilos = 0;
    for (int i = 0; i < animals.size(); i++) {
        if(dynamic_cast<Tiger*>(animals[i])!= nullptr){
            if (animals[i]->isMale()) {
                kilos += 12;
            } else if (!animals[i]->isMale() && animals[i]->isPregnant()) {
                kilos += 20;
            } else {
                kilos += 10;
            }
        } else if (dynamic_cast<Eagle*>(animals[i])!= nullptr){
            if (animals[i]->isMale()) {
                kilos += 0.25;
            } else if (!animals[i]->isMale() && animals[i]->isPregnant()) {
                kilos += 0.6;
            } else {
                kilos += 0.3;
            }
        } else {
            if (animals[i]->isMale()) {
                kilos += 0.15;
            } else if (!animals[i]->isMale() && animals[i]->isPregnant()) {
                kilos += 0.36;
            } else {
                kilos += 0.18;
            }
        }

    }
    return kilos;
}


void Habitat::addDay() {
    for (int i = 0; i < animals.size(); i++) {
        animals[i]->addDays();
    }
}

void Habitat::giveFood() {
    for (int i = 0; i < animals.size(); i++) {
        animals[i]->eat();
    }
}

void Habitat::checkCouple() {
    bool gotValideFemale = false;
    int valideFemaleIndex;
    bool gotValideMale = false;
    for (int i = 0; i < animals.size(); i++) {
        if (!animals[i]->isMale() && animals[i]->isMature() && !animals[i]->isHungry() && !animals[i]->isSick() && !animals[i]->isPregnant() && !animals[i]->getWaitNextPregnant()) {
            gotValideFemale = true;
            valideFemaleIndex = i;
        } else if ((dynamic_cast<Tiger*> (animals[i]) != nullptr && animals[i]->getlastTimePregnant() == 600) || (dynamic_cast<Eagle*> (animals[i])!= nullptr && animals[i]->getlastTimePregnant()==45)  || (dynamic_cast<Chicken*> (animals[i])!= nullptr && animals[i]->getlastTimePregnant()==42)) {
            gotValideFemale = true;
            valideFemaleIndex = i;
        }
        if (animals[i]->isMale() && animals[i]->isMature() && !animals[i]->isHungry() && !animals[i]->isSick()) {
            gotValideMale = true;
        }
    }
    if (gotValideFemale && gotValideMale) {
        cout << "startgestation" << animals[valideFemaleIndex]->getName() << endl;
        animals[valideFemaleIndex]->startGestation();
    }
}

void Habitat::checkHungry() {
    for (int i = 0; i < animals.size(); i++) {
        if (dynamic_cast<Tiger*>(animals[i])!= nullptr){
            if (animals[i]->isHungrySince() > 4) {
                cout << animals[i]->getName()<<" is die of hunger" << endl;
                animals[i]->killAnimal();
                animals.erase(animals.begin() + i);
            } else if (animals[i]->isHungrySince() > 2) {
                if (!animals[i]->isMale()) {
                    animals[i]->setHungry();
                    animals[i]->setPregenant(false);
                } else {
                    animals[i]->setHungry();
                }
            }
        } else if (dynamic_cast<Eagle*>(animals[i])!= nullptr){
            if (animals[i]->isHungrySince() > 20) {
                cout << animals[i]->getName()<<" is die of hunger" << endl;
                animals[i]->killAnimal();
                animals.erase(animals.begin() + i);
            } else if (animals[i]->isHungrySince() > 10) {
                if (!animals[i]->isMale()) {
                    animals[i]->setHungry();
                    animals[i]->setPregenant(false);
                } else {
                    animals[i]->setHungry();
                }
            }
        } else {
            if ((animals[i]->isHungrySince() > 2 && !animals[i]->isMale()) || ((animals[i]->isHungrySince() > 4 && animals[i]->isMale()))){
                cout << animals[i]->getName()<<" is die of hunger" << endl;
                animals[i]->killAnimal();
                animals.erase(animals.begin() + i);
            } else if ((animals[i]->isHungrySince() > 1 && !animals[i]->isMale()) || ((animals[i]->isHungrySince() > 2 && animals[i]->isMale()))) {
                if (!animals[i]->isMale()) {
                    animals[i]->setHungry();
                    animals[i]->setPregenant(false);
                } else {
                    animals[i]->setHungry();
                }
            }
        }
    }
}

void Habitat::isMature() {
    for (int i = 0; i < animals.size(); i++) {
        if (dynamic_cast<Tiger*>(animals[i])!= nullptr || dynamic_cast<Eagle*>(animals[i])!= nullptr ){
            if (!animals[i]->isMature()) {
                if (animals[i]->isMale() && animals[i]->getAge() >= 72) { // remettre 72
                    animals[i]->setMaturity(true);
                }
                if (!animals[i]->isMale() && animals[i]->getAge() >= 48) {
                    animals[i]->setMaturity(true);
                }
            }
            if (animals[i]->isMale() && animals[i]->getAge() == 168) {
                animals[i]->setMaturity(false);
            }
            if (!animals[i]->isMale() && animals[i]->getAge() == 168) {
                animals[i]->setMaturity(false);
            }
        } else {
            if (!animals[i]->isMature()) {
                if (animals[i]->isMale() && animals[i]->getAge() >= 6) {
                    animals[i]->setMaturity(true);
                }
                if (!animals[i]->isMale() && animals[i]->getAge() >= 6) {
                    animals[i]->setMaturity(true);
                }
            }
            if (animals[i]->isMale() && animals[i]->getAge() == 96) {
                animals[i]->setMaturity(false);
            }
            if (!animals[i]->isMale() && animals[i]->getAge() == 96) {
                animals[i]->setMaturity(false);
            }
        }
    }
}

void Habitat::checkGestation() {
    for (int i = 0; i < animals.size(); i++) {
        if (dynamic_cast<Tiger*>(animals[i])!= nullptr){
            if (animals[i]->isPregnant() && animals[i]->pregnantSince() == 90) {
                animals[i]->birth();
                cout << animals[i]->getName() << "start birth"<<endl;
                addTigrous();
            }
        } else if (dynamic_cast<Eagle*>(animals[i])!= nullptr){
            if (animals[i]->isPregnant() && animals[i]->pregnantSince() == 45) {
                animals[i]->birth();
                cout << animals[i]->getName() << "start birth"<<endl;
                addEaglouglou();
            }
        } else {
            if (animals[i]->isPregnant() && animals[i]->pregnantSince() == 42) {
                animals[i]->birth();
                cout << animals[i]->getName() << "start birth"<<endl;
                addKfc();
            }
        }
    }
}

void Habitat::addTigrous() {
    for (int i = 0; i < 3; i++) {
        int dead = rand() % 3 + 1;
        if (dead != 3) {
            bool male;
            string name;
            if (dead == 1) {
                cout << "Choose name for the male baby tiger :" << endl;
                cin >> name;
                male = true;
            } else {
                cout << "Choose name for the female baby tiger :" << endl;
                cin >> name;
                male = false;
            }
            Tiger *tigrou = new Tiger(male, name, 0);
            tigrou->setMaturity(false);
            addAnimal(tigrou);
        }
    }
}
void Habitat::addEaglouglou() {
    for (int i = 0; i < 1; i++) {
        int dead = rand() % 3 + 1;
        if (dead != 3) {
            bool male;
            string name;
            if (dead == 1) {
                cout << "Choose name for the male baby eagle :" << endl;
                cin >> name;
                male = true;
            } else {
                cout << "Choose name for the female baby eagle :" << endl;
                cin >> name;
                male = false;
            }
            Eagle *eaglouglou = new Eagle(male, name, 0);
            eaglouglou->setMaturity(false);
            addAnimal(eaglouglou);
        }
    }
}
void Habitat::addKfc() {
    for (int i = 0; i < 4; i++) {
        int dead = rand() % 3 + 1;
        if (dead != 3) {
            bool male;
            string name;
            if (dead == 1) {
                cout << "Choose name for the male baby rooster :" << endl;
                cin >> name;
                male = true;
            } else {
                cout << "Choose name for the female baby chicken :" << endl;
                cin >> name;
                male = false;
            }
            Chicken *kfcou= new Chicken(male, name, 0);
            kfcou->setMaturity(false);
            addAnimal(kfcou);
        }
    }
}

void Habitat::checkAge() {
    for (int i = 0; i < animals.size(); i++) {
        if ((animals[i]->getAge() == 350 && (dynamic_cast<Tiger*>(animals[i])!= nullptr || dynamic_cast<Eagle*>(animals[i])!= nullptr)) || (dynamic_cast<Chicken*>(animals[i])!=nullptr && animals[i]->getAge() == 180)) {
            animals[i]->killAnimal();
            animals.erase(animals.begin() + i);
        }
    }
}

void Habitat::checkSick() {
    double proba_annuelle;
    double proba_quotidienne;
    int duringSickness;
    for (int i = 0; i < animals.size(); i++) {
        if (dynamic_cast<Tiger*>(animals[i])!= nullptr){
            proba_annuelle = 0.3;
            proba_quotidienne = 1 - pow(1 - proba_annuelle, 1.0 / 365.0);
            duringSickness = 15;
        } else if (dynamic_cast<Tiger*>(animals[i])!= nullptr){
            proba_annuelle = 0.1;
            proba_quotidienne = 1 - pow(1 - proba_annuelle, 1.0 / 365.0);
            duringSickness = 30;
        } else {
            proba_annuelle = 0.05;
            proba_quotidienne = 1 - pow(1 - proba_annuelle, 1.0 / 365.0);
            duringSickness = 5;
        }
        double probabilite = static_cast<double>(rand()) / RAND_MAX;
        if (probabilite < proba_quotidienne) {
            cout << "tomber malade" << endl;
            if (animals[i]->isSick()) {
                cout << "dead sikeuh" << endl;
                animals[i]->killAnimal();
                animals.erase(animals.begin() + i);
            }
            animals[i]->setSick(true);
        }
        if (animals[i]->getSickSince() == duringSickness) {
            animals[i]->setSick(false);
        }
    }
}

vector<int> Habitat::showListAnimal() {
    vector<int>index;
    for( int i = 0; i < animals.size(); i++){
        index.push_back(i);
    }
    return index;
}

void Habitat::removeAnimal(int i) {
    animals.erase(animals.begin() + i);
}

int Habitat::estimateSellPriceByIndex(int index) {
    return (animals[index]->estimateBuyPrice())/2;
}





