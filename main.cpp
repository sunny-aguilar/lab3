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

    // show main menu and validate selection entered
    game.showStartMenu();
    game.setSelection( game.validateNumber(1, 2) );

    // begin the game
    if (game.getSelection() == 1) {
        // user plays the game
        cout << "starting game\n";


        bool playAgain;
        do {
            // ask user how many rounds to play
            game.submenuRounds();
            game.setRounds( game.validateNumber(1, 1000) );

            //  ask user the type of die for each player
            for (int player = 0; player < 2; player++) {
                game.submenuDiceType(player+1);

            }


            // ask user for number of sides for dice of both players


            // loop through the rounds to play
            for (int round = 0; round < game.getRounds(); round++) {

                cout << "Round #" << round+1 << endl;
                cout << "Hit [Enter] to continue\n";
                cin.get();

            }


            // ask user if they want to play again
            game.submenuReplay();
            game.setSelection( game.validateNumber(1, 2) );
            if (game.getSelection() == 2) {
                // control statement to play again
                game.submenuGameOver();
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