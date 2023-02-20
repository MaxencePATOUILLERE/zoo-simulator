#include <string>

using namespace std;

class Animal{
    string m_name;
    int m_age_month;
    int m_price=0;
public:
    Animal(string name, int age):m_name(name), m_age_month(age){};
    virtual int estimateBuyPrice()=0;
    virtual int getAge();
};