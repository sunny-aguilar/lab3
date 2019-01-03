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
using std::cin;
using std::cout;
using std::endl;

int main() {
    Die die(6);
    LoadedDie loadedDie(6);
//    cout << "Die " << die.randomInt() << endl;
//    cout << "Loaded Die " << loadedDie.randomInt() << endl;

    Game game;
    game.showStartMenu();
    game.validateNumber(1, 2);

    if (game.getSelection() == 1) {
        // user plays the game
        cout << "starting game\n";

        int rounds = 0;
        bool playAgain;
        do {


            rounds++;
            cout << "Round #" << rounds << endl;
            cout << "Hit [Enter] to continue\n";
            cin.get();

            if () {

            }
            else {

            }


        } while (rounds != 3);

        cout << "Game finished\n";
    }
    else if (game.getSelection() == 2) {
        // user quit the program in the main menu
        cout << "Goodbye\n";
    }
    else {
        cout << "Error processing your request!\n";
    }


    return 0;
}