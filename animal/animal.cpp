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
    if (m_pregnant) {
        addDaysPregnantSince();
    }
    if (m_waitForNextPregnant) {
        addDaysLTPrengnat();
    }
    if (m_sick) {
        m_sickSince++;
    }
    if (!m_sick) {
        m_sickSince = 0;
    }
    m_whenEat ++;
}

void Animal::eat() {
    m_whenEat = 0;
    m_hungry = false;
}

int Animal::isHungrySince() {
    return m_whenEat;
}

void Animal::killAnimal() {
    cout << "The animal " << m_name << " is dead this night" << endl;
    Animal::~Animal();
}

void Animal::setHungry() {
    m_hungry = true;
}

void Animal::setPregenant(bool pregenant) {
    m_pregnant = pregenant;
}

Animal::~Animal() {
}

void Animal::setMaturity(bool maturity) {
    m_sexualMat = maturity;
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
    m_pregnant = true;
    m_pregnantSince = 0;
    cout << "ENCEINTE" << endl;
}

void Animal::addDaysPregnantSince() {
    m_pregnantSince++;
}

int Animal::pregnantSince() {
    return m_pregnantSince;
}

void Animal::birth() {
    m_pregnant = false;
    m_pregnantSince = 0;
    m_waitForNextPregnant = true;
    m_lastTimePregnant = 0;
}

void Animal::setSick(bool sick) {
    m_sick = sick;
}

int Animal::getSickSince() {
    return m_sickSince;
}

void Animal::deleteAnimal() {
    Animal::~Animal();
}
