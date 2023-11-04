#ifndef CHICKEN_H
#define CHICKEN_H

// Include parent header
#include "Animal.h"

// Chicken animal
class Chicken : public Animal {
public:
    // Constructor that takes an optional x & y position
    Chicken(int x=0, int y=0);

    // The mandatory cry function overriding the one from the base class
    void cry() override;
};

#endif
