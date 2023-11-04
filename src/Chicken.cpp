#include "Chicken.h"
#include <iostream>

// Constructor
Chicken::Chicken(int x, int y):
    Animal("chicken",x ,y)
    {}

// The mandatory cry function, calls base cry with the cry
void Chicken::cry(){
    baseCry("clucka cluck");
};
