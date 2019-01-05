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

enum Dice {UNSET, NORMAL, LOADED};

class Game {
public:
    Game();
    void showStartMenu();
    int validateNumber(int min, int max);
    void setSelection(int sel);
    int getSelection();
    void submenuRounds();
    void setRounds(int rounds);
    int getRounds();
    void submenuDiceType(int player);
    void setDiceType(int player, int type);
    Dice getDiceType(int player);
    void setSides(Die &obj, int sides);
    void setSides(LoadedDie &obj, int sides);
    void setSidesChosenDice(Die &obj1, LoadedDie &obj2);
    int getRollValue(Die &obj1, LoadedDie &obj2, int player);
    void setplayerOneScore(int score);
    void setplayerTwoScore(int score);
    string updatePlayerScore(int p1Roll, int p2Roll);
    void addplayerOneScore();
    void addplayerTwoScore();
    int getplayerOneScore();
    int getplayerTwoScore();
    void submenueReport(std::string winner, int p1Roll, int p2Roll, int round);
    void submenuReplay();
    void submenuGameOver();

protected:
    int selection;                          // hold selection made
    int rounds;                             // hold rounds to play
    Dice diceType[2];                       // hold enum for dice type
    int playerOneScore;                     // hold player 1 score
    int playerTwoScore;                     // hold player2 score

private:
    void submenuSides(int player);          // internal use function
};

#endif
