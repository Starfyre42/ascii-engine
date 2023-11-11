#pragma once

#include "AbstractAnimal.h"
#include "AbstractLevel.h"
#include <ncurses.h>

class EntryLevel : public AbstractLevel {
public:
    EntryLevel(GameEngine& engine);
    virtual ~EntryLevel();

    virtual void start();
    virtual void stop();
    virtual void redraw();

    vector<unique_ptr<AbstractAnimal>> animals;

private:
    WINDOW* contentWindow;
    WINDOW* dialogWindow;
};
