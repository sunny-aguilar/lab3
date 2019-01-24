/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Game class implements the dice-rolling game. It
**                  sets the game elements such as showing menus,
 *                  validating user data, as well as keeping score.
 *                  The game class is not derived from and it is not
 *                  derived. Internal functions are labeled as private.
 *                  The class protected variables are used to set the
 *                  games parameters such as rounds to play and type of
 *                  dice to use.
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include "LoadedDie.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

enum Dice {UNSET, NORMAL, LOADED};              // enum datatype for dice

class Game {
public:
    Game();                                     // default constructor
    void playGame();
    void showStartMenu();                       // show start menu
    int validateNumber(int min, int max);       // validate data
    void setSelection(int sel);                 // setter of selection
    int getSelection();                         // getter of selection
    void submenuRounds();                       // show rounds menu
    void setRounds(int rounds);                 // setter for rounds
    int getRounds();                            // getter for rounds
    void submenuDiceType(int player);           // show dice type menu
    void setDiceType(int player, int type);     // setter for dice typ
    Dice getDiceType(int player);               // getter for dice type
    void setSidesChosenDice(Die &obj1, LoadedDie &obj2, int min, int max); // setter
    void rollDice();
    int getRollValue(Die &obj1, LoadedDie &obj2, int player);   // get roll
    void setplayerOneScore(int score);          // setter for player 1 score
    void setplayerTwoScore(int score);          // setter for player 2 score
    string updatePlayerScore(int p1Roll, int p2Roll);   // update player scores
    int getplayerOneScore();                    // getter for player one score
    int getplayerTwoScore();                    // getter for player two score
    void submenuReport(std::string winner, int p1Roll, int p2Roll, int round);
    bool replay();
    void submenuReplay();                       // show replay menu
    void submenuGameOver();                     // show game over menu

protected:
    int selection;                              // hold selection made
    int rounds;                                 // hold rounds to play
    Dice diceType[2];                           // hold enum for dice type
    int playerOneScore;                         // hold player 1 score
    int playerTwoScore;                         // hold player2 score

private:
    void submenuSides(int player, int minSides, int maxSides); // internal use function
    void setSides(Die &obj, int sides);         // setter for Die sides
    void setSides(LoadedDie &obj, int sides);   // setter for loadedDie sides
    void addplayerOneScore();                   // increase to player 1 score
    void addplayerTwoScore();                   // increase player 2 score
    Die dice;
    LoadedDie loadedDice;
};

#endif