#include <ctime>
#include <curses.h>

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
   
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);

    refresh();
    curs_set(0);

    contentWindow = newwin(height - 4, width, 0, 0);
    dialogWindow = newwin(4, width, height - 4, 0);
   
    wborder(dialogWindow, borderChar[2],borderChar[6], borderChar[0],borderChar[4],borderChar[7],borderChar[1],borderChar[5],borderChar[3]);
    wrefresh(dialogWindow);
    draw();
}

// The stop function just ends everything
void GameEngine::stop(){
    delwin(dialogWindow);
    delwin(contentWindow);
    endwin();  // End ncurses
}

// This will be made more complicated later on, it renders each frame
// Right now it's very simple and just draws a frame
void GameEngine::step(){
    draw();
}

// Draws a frame
void GameEngine::draw(){
   wclear(contentWindow);

   for (const auto& animal : animals) {
       mvwprintw(contentWindow, animal->y, animal->x,animal->symbol.c_str());
    }
    
    move(height, width);
    wborder(contentWindow, borderChar[2],borderChar[6], borderChar[0],borderChar[4],borderChar[7],borderChar[1],borderChar[5],borderChar[3]);
    wrefresh(contentWindow);
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