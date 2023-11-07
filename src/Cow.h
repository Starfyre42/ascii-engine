#pragma once

#include "Animal.h"

class Cow : public Animal{
    public:
        Cow(int x=0, int y=0);

        void cry() override;
};