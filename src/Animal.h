#pragma once

// Strings
#include <string>

using namespace std;

// This class contains base animal functonality but it cannot be
// used directly, only indirectly through children
class Animal{

    // We only want a few methods to be accessible to the rest of the program
    public:

    //adding a enum to represent direction in x and y
    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

    // All child classes are mandated to include the cry function
    // This provides a common interface to all child classes
    virtual void cry()=0;

    // The deconstructor for programming best practices
    virtual ~Animal();

    //move function for utilizing enum, x and y
    virtual void move(Direction dir);

    //implemention debug function
    virtual void dump();

    //variables 
    string species;
    string symbol;
    int x;
    int y;

    // These are available to any child class only
    protected:

    // Allow child classes to inherit from the base class
    // But prohibit this class from being instantiated directly
    Animal(string species, string symbol, int x=0, int y=0);

    // An internal method child classes can use to printout the cry
    void baseCry(string fx);
    
   
};
