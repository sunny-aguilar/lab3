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
                game.setSelection( game.validateNumber(1, 2) );
                game.setDiceType( player, game.getSelection() );
            }

            // ask user for number of sides for dice of both players
//            game.submenuSides();
            game.setSidesChosenDice(die, loadedDie);

            // loop through the rounds to play
            for (int round = 0; round < game.getRounds(); round++) {

                // roll player 1 and player 2 dice via for loop
                // player 1 rolls dice and store results in game in
                for (int player = 0; player < 2; player++) {
                    if (game.getDiceType(player) == NORMAL) {
                        if (player == 0) {
                            game.setplayerOneScore( die.randomInt() );
                        }
                        else if (player == 1) {
                            game.setplayerTwoScore( die.randomInt() );
                        }
                    }
                    else if (game.getDiceType(player) == LOADED) {
                        if (player == 0) {
                            game.setplayerOneScore( loadedDie.randomInt() );
                        }
                        else if (player == 1) {
                            game.setplayerTwoScore( loadedDie.randomInt() );
                        }
                    }
                }

                // output results
                // type of die and # of sides
                cout << "Player One dice being used is " << game.getDiceType(0) << endl;
                cout << "Player Two dice being used is " << game.getDiceType(1) << endl;
                // score result
                // number each player rolls
                cout << "Player One Score is " << game.getplayerOneScore() << endl;
                cout << "Player Two Score is " << game.getplayerTwoScore() << endl;

                cout << "Round #" << round+1 << endl;
                cout << "Hit [Enter] to continue\n";
                cin.get();

            }
            // afterwards, display the final score count
            // display final winner


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
                game.setplayerOneScore(0);
                game.setplayerTwoScore(0);
            }
        } while (playAgain);


        cout << "Game finished\n";
    }
    else if (game.getSelection() == 2) {
        // user quit the program in the main menu
//        cout << "Goodbye\n";
        game.submenuGameOver();
    }
    else {
        cout << "Error processing your request!\n";
    }


    return 0;
}