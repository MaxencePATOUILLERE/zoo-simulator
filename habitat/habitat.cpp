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
        } else if (animals[i]->isMale() == false && animals[i]->isPregnant()) {
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
        } else if (animals[i]->isMale() == false && animals[i]->isPregnant()) {
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
        } else if (animals[i]->isMale() == false && animals[i]->isPregnant()) {
            kilos += 0.36;
        } else {
            kilos += 0.18;
        }
    }
    return kilos;
}


