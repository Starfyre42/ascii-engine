#include <ctime>
#include <curses.h>

#include "GameEngine.h"
#include "AbstractLevel.h"

// Construtor, it just initializes a lot of variables and calls
// start if set to auto start
GameEngine::GameEngine(AbstractLevel* startingLevel, bool autoStart):
    curLevel(startingLevel),
    autoStart(autoStart)
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

    refresh();
    curs_set(0);

    if(curLevel !=nullptr)
        curLevel->start();
  
    redraw();
}

// The stop function just ends everything
void GameEngine::stop(){
    if(curLevel !=nullptr)
        curLevel->stop();

    endwin();  // End ncurses
}

// Draws a frame
void GameEngine::redraw(){
  if(curLevel !=nullptr)
        curLevel->redraw();
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
void GameEngine::changeLevel(AbstractLevel* newLevel){
    if(curLevel!=nullptr){
        curLevel->stop();
    }

    curLevel=newLevel;
    curLevel->start();
}

void GameEngine::drawBorder(WINDOW* win){
    wborder(
        win,
        border[2],
        border[6], 
        border[0],
        border[4],
        border[7],
        border[1],
        border[5],
        border[3]);
}

string GameEngine::border="-*|*-*|*";