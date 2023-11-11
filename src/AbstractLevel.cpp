#include "AbstractLevel.h"

// Constructor, just copy variables over
AbstractLevel::AbstractLevel(const int width, const int height, GameEngine& engine):
    engine(engine),
    width(width), 
    height(height) {
}

// Deconstructor, not used yet but needed regardless
AbstractLevel::~AbstractLevel(){
}