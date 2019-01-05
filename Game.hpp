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
    void submenuSides(int player);
    void setSides(Die &obj, int sides);
    void setSides(LoadedDie &obj, int sides);
    void setSidesChosenDice(Die &obj1, LoadedDie &obj2);
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
    int selection;
    int rounds;
    Dice diceType[2];
    int playerOneScore;
    int playerTwoScore;
};

#endif
