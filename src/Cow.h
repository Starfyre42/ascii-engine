#pragma once

#include "AbstractAnimal.h"

class Cow : public AbstractAnimal{
    public:
        Cow(int x=0, int y=0);

        void cry() override;
};