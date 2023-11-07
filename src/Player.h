#pragma once

#include "Animal.h"

class Player : public Animal {
public:
    // Constructor that takes an optional x & y position
    Player(int x=0, int y=0);

    // The mandatory cry function overriding the one from the base class
    void cry() override;
};