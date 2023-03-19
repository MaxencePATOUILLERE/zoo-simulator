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
    int m_whenEat;
    bool m_pregnant;
    int m_pregnantSince;
    int m_sickSince;
    string m_name;
    Time *m_time = new Time(0,0);
    bool m_waitForNextPregnant = false; // PASSE TRUE APRES L'ACCOUCHEMENT
    int m_lastTimePregnant = 0;
    int m_price=0;
public:
    Animal(bool male, string name, int age, int chanceSick):m_male(male), m_name(name), m_chanceSick(chanceSick){m_time->setMonth(age);};
    virtual int estimateBuyPrice()=0;
    int getAge();
    string getName();
    bool isMale();
    int getChanceSick();
    bool isPregnant();
    void addDays();
    void eat();
    int isHungrySince();
    void killAnimal();
    ~Animal();
    void setHungry();
    void setPregenant(bool pregenant);
    void setMaturity(bool maturity);
    bool isMature();
    bool isHungry();
    bool isSick();
    int getlastTimePregnant();
    void addDaysLTPrengnat();
    void addDaysPregnantSince();
    bool getWaitNextPregnant();
    void startGestation();
    int pregnantSince();

    void birth();

    void setSick(bool b);

    int getSickSince();
};

#endif