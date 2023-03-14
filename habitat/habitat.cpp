#include "habitat.h"

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
        if (animals[i]->getWaitNextPregnant()){
            animals[i]->addDaysLTPrengnat();
        }
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
            animals[i]->killAnimal();
        }else if(animals[i]->isHungrySince()>2){
            if (!animals[i]->isMale()){
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



