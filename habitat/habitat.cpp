#include "habitat.h"

int Habitat::getCapacity() {
    return m_capacity;
}

string Habitat::getAnimal() {
    return m_animal;
}

void Habitat::addAnimal(Animal* animal) {
    animals.push_back(animal);
}


