#include <ncurses.h>
#include <ctime>

#include "GameEngine.h"

// Construtor, it just initializes a lot of variables and calls
// start if set to auto start
GameEngine::GameEngine(int width,
    int height, 
    bool autoStart, 
    string borderChar,
    int borderOverdraw):
    width(width),
    height(height),
    autoStart(autoStart),
    borderChar(borderChar),
    borderOverdraw(borderOverdraw)
{
    // Auto start if set to
    if(autoStart)
        start();
}

// If the class is being destroyed, auto stop if it auto started
GameEngine::~GameEngine(){
    if(autoStart)
        stop();
}

// The start function does basic terminal setup
void GameEngine::start(){
    initscr();  // Initialize ncurses
    clear(); // Clear terminal
    noecho();  // Don't display user input
    cbreak();  // Line buffering disabled
    keypad(stdscr, TRUE);  // Enable special keys
}

// The stop function just ends everything
void GameEngine::stop(){
    endwin();  // End ncurses
}

// This will be made more complicated later on, it renders each frame
// Right now it's very simple and just draws a frame
void GameEngine::step(){
    draw();
}

// Draws a frame
void GameEngine::draw(){
    clear();  // Clear the screen

    // Draw the top border with some overdraw
    for (int i = 0; i < width + borderOverdraw; i++) {
        printw(borderChar.c_str());
    }
    printw("\n");

    // Loop through each cell in the grid and fill it with something
    // Auto prepend borders to left and right
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // If the column is at the start of the row, then prepend a border
            // j = column, so j == 0 means the 1st column of the current row or
            // the start of the row
            if (j == 0) {
                printw(borderChar.c_str());  // Draw the left border
            }
   
            // This normally needs to be more complex, but right now we keep it
            // simple, it just prints an empty character (space)
            printw(" ");

            // If we're at the end of the row, append the right border
            // a row or column starts at zero meaning the last element is 1 less than the size
            // so 1 less than with is the last element of a row
            // j = column, so this means the last column of the current row
            if (j == width - 1) {
                printw(borderChar.c_str());  // Draw the right border
            }
        }
        printw("\n");
    }

    // Draw the bottom border
    for (int i = 0; i < width + borderOverdraw; i++) {
        printw(borderChar.c_str());
    }
    printw("\n");

    // This is reserved for messages below the game window
    // But it's unimplemented thus far
    //printw("Score: %d\n", score);
    refresh();
}

// This pauses and asks the user to press any key to continue
void GameEngine::askContinue(){
    printw("Press any key to continue..."); // print function in ncurses
    refresh();//dispays the print statement 
    getch();//waits on the user to enter a key
}

// This gets user input, it needs to be more complex but right now
// it's very simple
int GameEngine::getInput(){
    return getch();
}