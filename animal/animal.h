#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "resources.h"

using namespace std;

class Animal{
    bool m_male;
    bool m_sexualMat;
    int m_chanceSick;
    bool m_sick;
    bool m_hungry;
    string m_name;
    Time *m_time = new Time(0,0);
    int m_price=0;
public:
    Animal(bool male, string name, int age, int chanceSick):m_male(male), m_name(name), m_chanceSick(chanceSick){m_time->setMonth(age);};
    virtual int estimateBuyPrice()=0;
    int getAge();
    string getName();
    bool isMale();
    int getChanceSick();
};

#endif