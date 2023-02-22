#include "female_tiger.h"

int Female_tiger::estimateBuyPrice() {
    if (getAge() <= 6){
        return 3000;
    }
    if (getAge() <= 48){
        return 120000;
    }
    if(getAge() <= 168){
        return 60000;
    }
}
