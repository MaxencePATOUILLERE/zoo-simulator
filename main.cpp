#include <iostream>
#include <string>
#include "MenuActions.h"
using namespace std;


int main() {
    MenuActions menu;
    menu.createZoo();
    while(1){
        menu.chooseAction();
    }
    return 0;
}