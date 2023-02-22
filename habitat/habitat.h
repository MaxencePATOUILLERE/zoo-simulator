#include <string>

using namespace std;

class Habitat{
    string m_name;
    int m_price=0;
    int m_capacity=0;
public:
    Habitat(string name, int price, int capacity):m_name(name), m_price(price), m_capacity(capacity){};
    virtual int estimateBuyPrice()=0;
    virtual int estimateSellPrice()=0;
    virtual int getCapacity()=0;
};