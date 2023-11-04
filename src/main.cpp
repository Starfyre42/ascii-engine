// cout, cin, etc...
#include <iostream>

// EXIT_SUCCESS
#include <cstdlib>

// Smart arrays
#include <vector>

// Smart pointers
#include <memory>

//adds the ncurses library and system time
#include <ncurses.h>
#include <ctime>

// This apps code
#include "Animal.h"
#include "Chicken.h"
#include "Cow.h"
#include "GameEngine.h"

using namespace std;

int main()
{
    srand(time(0));  // Seed the random number generator

    // Put the engine on the heap and ask c++ to auto-manage it with smart
    // pointers
    // We make it 20x10 in size
    // autoStart is on, so by creating the engine here, it automatically takes over the
    // terminal and starts the engine
    unique_ptr<GameEngine> engine = make_unique<GameEngine>(20,10);

    // Vector = Smart array
    // Unique Pointer = Smart Pointer that excusively owns a pointer and refuses
    // to share it with anything else
    // vector<unique_ptr<Animal>> = A smart array of smart pointers that will
    // put things on the heap for you and take them off for you and manage an array
    // easily for you
    vector<unique_ptr<Animal>> animals;

    // push_back adds an array element to the end of the list
    // make_unique instantiates a class onto the heap and returns an exclusive
    // smart pointer which is managed by unique_pointer above
    animals.push_back(make_unique<Chicken>(5,4));
    animals.push_back(make_unique<Cow>(2,2));
    animals.push_back(make_unique<Chicken>(1,3));

    //creating background movement
    animals[0]->move(Animal::RIGHT);

    // Simplified for loop, loops over all animals and allows you to work
    // with each one individually
    //for (const auto& animal : animals) {

        // Ask each animal to cry, replace cry with dump to enter debug
        //animal->dump();

        //cout<<"------------"<<endl<<endl;
    //}

    // Step the engine forward a frame, then check for the exit key
    // If the exit key is pressed, stop rendering frames, otherwise
    // keep rendering them
    do {
        engine->step();
    } while(engine->getInput() != 'x');

    // The exit key was pressed, so ask the user to press a key to continue
    engine->askContinue();

    // Return the program ran successfully
    return EXIT_SUCCESS;

    // At this point the smart pointer auto-deletes the engine from heap, this
    // means the engines deconstructor is automatically called meaning it
    // auto stops the engine and gives control back to the terminal
}
