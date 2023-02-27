#include "eagle.h"

int Eagle::estimateBuyPrice() {
    if (getAge() <= 6){
        return 1000;
    }
    if (getAge() <= 48){
        return 4000;
    }
    if(getAge() <= 168){
        return 2000;
    }
}