/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Die.hpp"
#include "LoadedDie.hpp"
#include <string>
using std::string;

enum Dice {UNSET, NORMAL, LOADED};              // enum datatype for dice

class Game {
public:
    Game();                                     // default constructor
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
    void setSides(Die &obj, int sides);         // setter for Die sides
    void setSides(LoadedDie &obj, int sides);   // setter for loadedDie sides
    void setSidesChosenDice(Die &obj1, LoadedDie &obj2);        // setter
    int getRollValue(Die &obj1, LoadedDie &obj2, int player);   // get roll
    void setplayerOneScore(int score);          // setter for player 1 score
    void setplayerTwoScore(int score);          // setter for player 2 score
    string updatePlayerScore(int p1Roll, int p2Roll);   // update player scores
    void addplayerOneScore();                   // increase to player 1 score
    void addplayerTwoScore();                   // increase player 2 score
    int getplayerOneScore();                    // getter for player one score
    int getplayerTwoScore();                    // getter for player two score
    void submenueReport(std::string winner, int p1Roll, int p2Roll, int round);
    void submenuReplay();                       // show replay menu
    void submenuGameOver();                     // show game over menu

protected:
    int selection;                              // hold selection made
    int rounds;                                 // hold rounds to play
    Dice diceType[2];                           // hold enum for dice type
    int playerOneScore;                         // hold player 1 score
    int playerTwoScore;                         // hold player2 score

private:
    void submenuSides(int player);              // internal use function
};

#endif
