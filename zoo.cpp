#include "zoo.h"
#include <iostream>

using namespace std;

void Zoo::buyAnimal(Animal* animal) {
    if (canBuy(animal)){

        m_money -= animal->estimateBuyPrice();
        cout << "You have: " << getMoney() << "money" << endl;
        cout << "Your tiger name's: " << animal->getName() << "and he's old is: " << animal->getAge() << endl;
        return;
    }
    cout << "You don't have enough money" << endl;
}

void Zoo::sellAnimal(Animal* animal){

}

void Zoo::buyFood(Food* food){

}

void Zoo::buyHabitat(Habitat* habitat){

};

void Zoo::sellHabitat(Habitat* habitat){
    
}

bool Zoo::canBuy(Animal *animal) {
    if (m_money>animal->estimateBuyPrice()){
        return true;
    }
    return false;
}

int Zoo::getMoney() {
    return m_money;
}
