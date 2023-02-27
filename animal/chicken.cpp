#include "chicken.h"

int Chicken::estimateBuyPrice() {
   if (isMale()==true){
       return 100;
   }
    return 20;
}