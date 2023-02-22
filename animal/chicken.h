#include "string"
#include "animal.h"

using namespace std;

class Chicken : public Animal{
public:
    Chicken(string name, int age_month)
    :Animal(name, age_month){};
    virtual int estimateBuyPrice();
    virtual int getAge(); //pas utilisée, mais si on la met pas->erreur dans le main
};