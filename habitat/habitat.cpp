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

int Habitat::estimateTigerFood() {
    int kilos = 0;
    for (int i = 0; i < animals.size(); i++) {
        if (animals[i]->isMale()) {
            kilos += 12;
        } else if (!animals[i]->isMale() && animals[i]->isPregnant()) {
            kilos += 20;
        } else {
            kilos += 10;
        }
    }
    return kilos;
}

int Habitat::estimateEagleFood() {
    float kilos = 0;
    for (int i = 0; i < animals.size(); i++) {
        if (animals[i]->isMale()) {
            kilos += 0.25;
        } else if (!animals[i]->isMale() && animals[i]->isPregnant()) {
            kilos += 0.6;
        } else {
            kilos += 0.3;
        }
    }
    return kilos;
}

int Habitat::estimateChickenFood() {
    float kilos = 0;
    for (int i = 0; i < animals.size(); i++) {
        if (animals[i]->isMale()) {
            kilos += 0.15;
        } else if (!animals[i]->isMale() && animals[i]->isPregnant()) {
            kilos += 0.36;
        } else {
            kilos += 0.18;
        }
    }
    return kilos;
}

void Habitat::addDay() {
    for (int i = 0; i < animals.size(); i++){
        animals[i]->addDays();
    }
}

void Habitat::giveFood() {
    for (int i = 0; i < animals.size(); i++){
        animals[i]->eat();
    }
}

void Habitat::checkCoupleTiger() {
    bool gotValideFemale = false;
    int valideFemaleIndex;
    bool gotValideMale = false;
    for (int i = 0; i < animals.size();i++){
        if (!animals[i]->isMale() && animals[i]->isMature() && !animals[i]->isHungry() && !animals[i]->isSick() && animals[i]->getlastTimePregnant()>=600 && getCapacity()>= 5){
            gotValideFemale = true;
            valideFemaleIndex = i;
        }
        if (animals[i]->isMale() && animals[i]->isMature() && !animals[i]->isHungry() && !animals[i]->isSick() && getCapacity()>= 5){
            gotValideMale = true;
        }
    }
    if (gotValideFemale && gotValideMale){
        animals[valideFemaleIndex]->startGestation();
    }
}

void Habitat::checkHungryTiger() {
    for (int i = 0; i < animals.size(); i++){
        if(animals[i]->isHungrySince()>4){
            cout << "dead hungyyy" << endl;
            animals[i]->killAnimal();
        }else if(animals[i]->isHungrySince()>2){
            if (!animals[i]->isMale()){
                animals[i]->setHungry();
                animals[i]->setPregenant(false);
            }else{
                animals[i]->setHungry();
            }
        }
    }
}

void Habitat::isMatureTiger() {
    for (int i = 0; i < animals.size(); i++){
        if (animals[i]->isMale() && animals[i]->getAge()==72){
            animals[i]->setMaturity(true);
        } else if (animals[i]->isMale() && animals[i]->getAge()==168){
            animals[i]->setMaturity(false);
        }
        if (!animals[i]->isMale() && animals[i]->getAge() == 48){
            animals[i]->setMaturity(true);
        } else if (!animals[i]->isMale() && animals[i]->getAge()==168){
            animals[i]->setMaturity(false);
        }
    }
}

void Habitat::checkGestation() {
    for (int i = 0; i < animals.size(); i++) {
        if (animals[i]->isPregnant() &&   animals[i]->pregnantSince() == 90) {
            animals[i]->birth();
            addTigrous(); //change bool//mortalité infantile 33%//3 tigrous par portée
        }
    }
}

void Habitat::addTigrous() {
    for (int i = 1; i <= 3;i++){
        int dead = rand() % 3 + 1;
        if (dead != 3){
            bool male;
            string name;
            if (dead == 1){
                cout << "Choose name for the male baby tiger :" << endl;
                cin >> name;
                male = true;
            }else{
                cout << "Choose name for the female baby tiger :" << endl;
                cin >> name;
                male = false;
            }
            Tiger *tigrou = new Tiger(male,name,0);
            addAnimal(tigrou);
        }
    }
}

void Habitat::checkTigerAge() {
    for (int i = 0; i < animals.size(); i++){
        if (animals[i]->getAge()== 168){
            animals[i]->killAnimal();
        }
    }
}

void Habitat::checkSickTiger() {
    double proba_annuelle = 0.3; // probabilité annuelle de tomber malade
    double proba_quotidienne = 1 - pow(1 - proba_annuelle, 1.0/365.0); // probabilité quotidienne de tomber malade

    for (int i = 0; i < animals.size(); i++) {
        double probabilite = static_cast<double>(rand()) / RAND_MAX;
        if (probabilite < proba_quotidienne) {
            cout << "tomber malade"<<endl;
            if (animals[i]->isSick()) {
                cout << "dead sikeuh" << endl;
                animals[i]->killAnimal();
            }
            animals[i]->setSick(true);
        }
        if (animals[i]->getSickSince() == 15) {
            animals[i]->setSick(false);
        }
    }
}




