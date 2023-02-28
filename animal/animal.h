#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal{
    bool m_male;
    int m_chanceSick;
    bool m_sick;
    string m_name;
    int m_age_month=0;
    int m_price=0; // pas utilisé
public:
    Animal(bool male, string name, int age, int chanceSick):m_male(male), m_name(name), m_age_month(age), m_chanceSick(chanceSick){};
    virtual int estimateBuyPrice()=0;
    int getAge();
    string getName();
    bool isMale();
    int getChanceSick();
};

#endif