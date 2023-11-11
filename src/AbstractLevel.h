#pragma once

#include "GameEngine.h"

// This provides a common interface to all game levels
class AbstractLevel{
public:
    // Deconstructor which needs to be public and virtual so that child
    // deconstructors are called properly
    virtual ~AbstractLevel();

    // Interface to child methods
    virtual void start()=0;     // Begin level (auto-called by the engine)
    virtual void stop()=0;      // Stop level (auto-called by the engine)
    virtual void redraw()=0;    // Redraw/Draw frame (auto-called by the engine)

    // Below here is only available to child classes (Levels)
protected:
    // Constructor that just copies variables to the class
    AbstractLevel(const int width, const int height, GameEngine& engine);
    
    // A level needs to be able to direct the engine as needed
    // This gets a reference to the game engine
    GameEngine& engine;

    // Map size, levels can set this and change this
    int width;
    int height;
};