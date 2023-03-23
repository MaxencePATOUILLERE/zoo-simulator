#include "food.h"

double Food::getKilos() {
    return m_kilos;
}

void Food::addKilos(double kilos) {
    m_kilos+=kilos;
}


void Food::removeKilos(double kilos) {
    m_kilos-=kilos;
}
