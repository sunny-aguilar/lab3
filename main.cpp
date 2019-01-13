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
 *                  be run by running make with the supplies files.
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
    unsigned seed = static_cast<unsigned int>(time(nullptr));    // random number variables
    srand(seed);

    // create objects of each class
    Die die(0);
    LoadedDie loadedDie(1);
    Game game;
    const int MIN_SEL = 1;              // hold min menu selection
    const int MAX_SEL = 2;              // hold max menu selection
    const int MIN_ROUND = 1;            // hold min number of rounds
    const int MAX_ROUND = 1000;         // hold max number of rounds
    const int MIN_SIDES = 3;
    const int MAX_SIDES = 20;

    // show main menu and validate selection entered
    game.showStartMenu();
    game.setSelection( game.validateNumber(MIN_SEL, MAX_SEL) );

    // begin the game
    if (game.getSelection() == 1) {
        // track if player wants to play again
        bool playAgain;

        // user plays the game
        cout << "\nStarting Game\n\n";
        do {
            // prompt user to enter rounds and validate it
            game.submenuRounds();
            game.setRounds( game.validateNumber(MIN_ROUND, MAX_ROUND) );

            //  ask user the type of die for each player
            for (int player = 0; player < 2; player++) {
                game.submenuDiceType(player+1);
                game.setSelection( game.validateNumber(MIN_SEL, MAX_SEL) );
                game.setDiceType( player, game.getSelection() );
            }

            // ask user for number of sides for dice of both players
            game.setSidesChosenDice(die, loadedDie, MIN_SIDES, MAX_SIDES);

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
            game.setSelection( game.validateNumber(MIN_SEL, MAX_SEL) );
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