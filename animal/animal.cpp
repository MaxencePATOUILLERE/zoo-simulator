#include "animal.h"
#include "iostream"

int Animal::getAge() {
    return m_time->getMonth();
}

string Animal::getName() {
    return m_name;
}

bool Animal::isMale() {
    if (m_male) {
        return true;
    }
    return false;
}

int Animal::getChanceSick() {
    return m_chanceSick;
}

bool Animal::isPregnant() {
    return m_pregnant;
}

void Animal::addDays() {
    m_time->setDay(1);
}

void Animal::eat() {
    m_whenEat = 0;
    m_hungry = false;
}

int Animal::isHungrySince() {
    return m_whenEat;
}

void Animal::killAnimal() {
    Animal::~Animal();
}

void Animal::setHungry() {
    m_hungry = true;
}

void Animal::setPregenant(bool pregenant) {
    m_pregnant = pregenant;
}

Animal::~Animal() {
    cout << "The animal " << m_name << " is dead this night"<<endl;
}

void Animal::setMaturity(bool maturity) {
    m_sexualMat=maturity;
}

bool Animal::isMature() {
    return m_sexualMat;
}

bool Animal::isHungry() {
    return m_hungry;
}

bool Animal::isSick() {
    return m_sick;
}

int Animal::getlastTimePregnant() {
    return m_lastTimePregnant;
}

bool Animal::getWaitNextPregnant() {
    return m_waitForNextPregnant;
}

void Animal::addDaysLTPrengnat() {
    m_lastTimePregnant++;
}

void Animal::startGestation() {

}