#include "EntryLevel.h"

// Constructor, Just sets the map size to be 20x10
EntryLevel::EntryLevel(GameEngine& engine):
    AbstractLevel(20,10,engine){
    
}

// Deconstructor we're not using yet
EntryLevel::~EntryLevel(){}

// Begin the level
void EntryLevel::start(){ 

    // Create a content and dialog window
    contentWindow = newwin(height - 4, width, 0, 0);
    dialogWindow = newwin(4, width, height - 4, 0);

    // Add a border to it
    engine.drawBorder(dialogWindow);

    // Display it
    wrefresh(dialogWindow);
}

// End the level
void EntryLevel::stop(){
    delwin(dialogWindow);
    delwin(contentWindow);
}

// Redraw/Draw the frame
void EntryLevel::redraw(){
    wclear(contentWindow);

    for (const auto& animal : animals) {
        mvwprintw(contentWindow, animal->y, animal->x,animal->symbol.c_str());
    }
    
    move(height, width);
    engine.drawBorder(contentWindow);
    wrefresh(contentWindow);
}
