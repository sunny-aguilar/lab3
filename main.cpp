/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This is a 2-player game that is placed through
**                  dice. The player who rolls a higher number gets
**                  one point. If both players roll the same number, it
**                  is considered a draw and no one gets a point.
 *                  Implemented using a Game class, a Die class, and
 *                  a loadedDie class. Die class is the superclass and
 *                  the loadedDie class is the sub class. Program can
 *                  be run by running make with the supplied files.
 *********************************************************************/
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);                // create random number generator
    Game game;                  // create game object
    game.playGame();            // play the game
    return 0;
}