#include "food.h"

int Food::getKilos() {
    return m_kilos;
}

void Food::addKilos(int kilos) {
    m_kilos+=kilos;
}
