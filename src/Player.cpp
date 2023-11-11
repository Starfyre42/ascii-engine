#include "Player.h"
#include <iostream>

// Constructor
Player::Player(int x, int y):
    AbstractAnimal("Player","@",x ,y)
    {}

// The mandatory cry function, calls base cry with the cry
void Player::cry(){
    baseCry("my sausage is not fried");
};
