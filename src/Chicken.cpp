#include "Chicken.h"
#include <iostream>

// Constructor
Chicken::Chicken(int x, int y):
    AbstractAnimal("chicken","c",x ,y)
    {}

// The mandatory cry function, calls base cry with the cry
void Chicken::cry(){
    baseCry("clucka cluck");
};
