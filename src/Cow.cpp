#include "Cow.h"
#include <iostream>

Cow::Cow(int x,int y):
    Animal("cow",x,y)
    {}

void Cow::cry(){
    baseCry("bow wow ima cow");
}
