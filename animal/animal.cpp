#include "animal.h"

int Animal::getAge() {
    return m_age_month;
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
