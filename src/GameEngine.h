#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>

#include "Animal.h"

using namespace std;

// Represents a game engine, this will takeover the terminal
// If planning to use the terminal for anything else or to have multiple
// engines running you will need to ask it to stop first
class GameEngine{
public:

    // Constructor that takes a width and height plus optional settings
    GameEngine(int width,
        int height, 
        bool autoStart=true, 
        string borderChar="-*|*-*|*", 
        int borderOverdraw=2);

    // Deconstructor
    ~GameEngine();

    // Functions to control the engine
    // These two are called for you if autoStart is enabled
    void start();   // Takeover terminal exclusively
    void stop();    // Release control over terminal

    void step(); // Render next frame
    void askContinue(); // Pause and ask to continue
    int getInput(); // Get input key
    
    vector<unique_ptr<Animal>> animals;

private:
    void draw(); // Draw the frame

    // Width and Height of engine display
    int width;
    int height;

    // Whether it should auto start and stop or not
    bool autoStart;

    // The border character
    string borderChar;

    // How much longer the top and bottom border should be
    int borderOverdraw;

    //creates windows ncurses/fuck C
    WINDOW* contentWindow;
    WINDOW* dialogWindow;
};