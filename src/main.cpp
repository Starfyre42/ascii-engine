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

// To add utf-8 support
#include <locale.h>

// This apps code
#include "Animal.h"
#include "Chicken.h"
#include "Cow.h"
#include "GameEngine.h"
#include "Player.h"

using namespace std;

int main()
{
    srand(time(0));  // Seed the random number generator
    setlocale(LC_ALL, ""); // Enable UTF-8 support

    // Put the engine on the heap and ask c++ to auto-manage it with smart
    // pointers
    // We make it 20x10 in size
    // autoStart is on, so by creating the engine here, it automatically takes over the
    // terminal and starts the engine
    unique_ptr<GameEngine> engine = make_unique<GameEngine>(20,10);

    // push_back adds an array element to the end of the list
    // make_unique instantiates a class onto the heap and returns an exclusive
    // smart pointer which is managed by unique_pointer above
    engine->animals.push_back(make_unique<Player>(1,1));
    engine->animals.push_back(make_unique<Chicken>(3,1));
    engine->animals.push_back(make_unique<Cow>(2,2));
    engine->animals.push_back(make_unique<Chicken>(1,3));

    // Step the engine forward a frame, then check for the exit key
    // If the exit key is pressed, stop rendering frames, otherwise
    // keep rendering them
    int ch;
    do {
        switch(ch){
            case 'w':
                engine->animals[0]->move(Animal::Direction::UP);
                break;
            case 'a':
                engine->animals[0]->move(Animal::Direction::LEFT);
                break;
            case 's':
                engine->animals[0]->move(Animal::Direction::DOWN);
                break;
            case 'd':
                engine->animals[0]->move(Animal::Direction::RIGHT);
                break;
        }
        engine->step();
    } while((ch = engine->getInput()) != 'x');

    // The exit key was pressed, so ask the user to press a key to continue
    engine->askContinue();

    // Return the program ran successfully
    return EXIT_SUCCESS;

    // At this point the smart pointer auto-deletes the engine from heap, this
    // means the engines deconstructor is automatically called meaning it
    // auto stops the engine and gives control back to the terminal
}
