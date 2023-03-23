#ifndef FOOD_H
#define FOOD_H

#include <string>

using namespace std;

class Food{
    double m_kilos=0;
public:
    Food(double kilos):m_kilos(kilos){};
    void addKilos(double kilos);
    double getKilos();
    void removeKilos(double kilos);
};

#endif