#include "string"
#include "animal.h"

using namespace std;

class Male_tiger : public Animal{

public:
    Male_tiger(string name, int age_month)
    :Animal(name, age_month){};
    virtual int estimateBuyPrice();
};
