#ifndef COW_H
#define COW_H

#include "Animal.h"

class Cow : public Animal{
    public:
        Cow(int x=0, int y=0);

        void cry() override;
};

#endif