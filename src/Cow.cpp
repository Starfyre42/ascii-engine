#include "Cow.h"
#include <iostream>

Cow::Cow(int x,int y):
    Animal("cow","m",x,y)
    {}

void Cow::cry(){
    baseCry("bow wow ima cow");
}
