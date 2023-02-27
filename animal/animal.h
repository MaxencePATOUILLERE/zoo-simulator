#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal{
    bool m_male;
    string m_name;
    int m_age_month=0;
    int m_price=0; // pas utilisé
public:
    Animal(bool male, string name, int age):m_male(male), m_name(name), m_age_month(age){};
    virtual int estimateBuyPrice()=0;
    int getAge();
    string getName();
    bool isMale();
};

#endif