#include "animal.h"

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
