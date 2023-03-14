#include "food.h"

int Food::getKilos() {
    return m_kilos;
}

void Food::addKilos(int kilos) {
    m_kilos+=kilos;
}


void Food::removeKilos(int kilos) {
    m_kilos-=kilos;
}
