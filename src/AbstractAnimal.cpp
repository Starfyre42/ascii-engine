#include <iostream>
#include "AbstractAnimal.h"

// Constructor
AbstractAnimal::AbstractAnimal(string species,string symbol, int x, int y):
    species(species),
    symbol(symbol),
    x(x),
    y(y)
    {}

// Base cry to print out for child classes
void AbstractAnimal::baseCry(string fx){
    cout<<fx<< endl;
}

// Deconstructor for programming best practices but we're not using it
AbstractAnimal::~AbstractAnimal(){}

//move function that allows animals to move based around the direction enumeration
//note that y-- is up, x++ is right, y++ is down and x-- is left
// It takes a direction and moves the entity accordingly
void AbstractAnimal::move(Direction dir){
    switch (dir){
        case UP:
            y--;
            break;
        case RIGHT:
            x++;
            break;
        case LEFT:
            x--;
            break;
        case DOWN:
            y++;
            break;
    }
}

// Debug dump
void AbstractAnimal::dump(){
    cout<<species<<endl;
    cout<<x<<endl;
    cout<<y<<endl;
}