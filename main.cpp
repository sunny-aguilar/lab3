/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This is a 2-player game that is placed through
**                  dice. The player who rolls a higher number gets
**                  one point. If both players roll the same number, it
**                  is considered a draw and no one gets a point.
 *                  Implemented using a Game class, a Die class, and
 *                  a loadedDie class. Die class is the superclass and
 *                  the loadedDie class is the sub class.
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
    // create objects of each class
    Die die(0);
    LoadedDie loadedDie(0);
    Game game;

    // show main menu and validate selection entered
    game.showStartMenu();
    game.setSelection( game.validateNumber(1, 2) );

    // begin the game
    if (game.getSelection() == 1) {
        // track if player wants to play again
        bool playAgain;

        // user plays the game
        cout << "\nStarting Game\n\n";
        do {
            // show menu that asks user how many rounds to play
            game.submenuRounds();
            // get user validated user input
            game.setRounds( game.validateNumber(1, 1000) );

            //  ask user the type of die for each player
            for (int player = 0; player < 2; player++) {
                game.submenuDiceType(player+1);
                game.setSelection( game.validateNumber(1, 2) );
                game.setDiceType( player, game.getSelection() );
            }

            // ask user for number of sides for dice of both players
            game.setSidesChosenDice(die, loadedDie);

            // loop through the rounds to play
            for (int round = 0; round < game.getRounds(); round++) {

                // roll dice for player 1 and player 2 and assign values to variables
                int p1RollScore = 0, p2RollScore = 0;
                p1RollScore = game.getRollValue(die, loadedDie, 0);
                p2RollScore = game.getRollValue(die, loadedDie, 1);

                // update winner score
                std::string winner;
                winner = game.updatePlayerScore(p1RollScore, p2RollScore);

                // display game results after each round
                game.submenueReport(winner, p1RollScore, p2RollScore, round+1);

                // end of round pause to view game report
                cout << "\nHit [Enter] to continue\n";
                cin.get();
            }

            // ask user if they want to play again and play again or quit
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

        // game has ended message
        cout << "Game finished\n";
    }
    else if (game.getSelection() == 2) {
        // user quit the program in the main menu and game quits
        game.submenuGameOver();
    }
    else {
        // error processing main menu input
        cout << "Error processing your request!\n";
    }

    return 0;
}