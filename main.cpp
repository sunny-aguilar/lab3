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
    game.setSelection( game.validateNumber(1, 2) );


    if (game.getSelection() == 1) {
        // user plays the game
        cout << "starting game\n";

        int rounds = 0;
        bool playAgain;
        do {

            game.submenuRounds();
            game.setRounds( game.validateNumber(1, 1000) );



            rounds++;
            cout << "Round #" << rounds << endl;
            cout << "Hit [Enter] to continue\n";
            cin.get();




            // ask user if they want to play again
            game.submenuReplay();
            game.validateNumber(1, 2);
            if (game.getSelection() == 2) {
                // control statement to play again
                cout << "Thanks for playing!\n";
                playAgain = false;
            }
            else {
                playAgain = true;
            }
        } while (playAgain);


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