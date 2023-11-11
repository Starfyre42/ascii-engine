#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

// GameEngine can't include AbstractLevel while AbstractLevel includes GameEngine
// Only 1 can include the other
// So we are letting AbstractLevel include GameEngine
// and here we are promising the compiler that AbstractLevel does exist even if we can't
// properly include it. The linker will seek out the class and link it up properly
// This is just to get the compiler happy
class AbstractLevel;

using namespace std;

// Represents a game engine, this will takeover the terminal
// If planning to use the terminal for anything else or to have multiple
// engines running you will need to ask it to stop first
class GameEngine{
public:

    // Constructor that takes a width and height plus optional settings
    GameEngine(AbstractLevel* startingLevel=nullptr, bool autoStart=true);

    // Deconstructor
    ~GameEngine();

    // Functions to control the engine
    // These two are called for you if autoStart is enabled
    void start();   // Takeover terminal exclusively
    void stop();    // Release control over terminal
    void redraw(); // Draw the frame

    void askContinue(); // Pause and ask to continue
    int getInput(); // Get input key
    void drawBorder(WINDOW* win);
    void changeLevel(AbstractLevel* newLevel);
    
    AbstractLevel* curLevel;
    static string border; 

private:
    // Whether it should auto start and stop or not
    bool autoStart;    
};