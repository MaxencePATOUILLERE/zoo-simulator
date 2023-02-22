#include "string"
#include "animal.h"

using namespace std;

class Female_eagle : public Animal{

public:
    Female_eagle(string name, int age_month)
    :Animal(name, age_month){};
    virtual int estimateBuyPrice();
    virtual int getAge();
};