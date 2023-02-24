#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal{
    string m_name;
    int m_age_month=0;
    int m_price=0; // pas utilisé
public:
    Animal(string name, int age):m_name(name), m_age_month(age){};
    virtual int estimateBuyPrice()=0;
    virtual int getAge()=0;
};

#endif