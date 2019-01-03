/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Die die(6);
    LoadedDie loadedDie(6);
//    cout << "Die " << die.randomInt() << endl;
//    cout << "Loaded Die " << loadedDie.randomInt() << endl;

    Game game;
    game.showStartMenu();


    if (game.validateNumber(1, 2) == 1) {
        cout << "start game\n";
    }
    else {
        // user quit the program in the main menu
        cout << "Goodbye\n";
    }


    return 0;
}