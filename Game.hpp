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

class Game {
public:
    Game();
    void showStartMenu();
    int validateNumber(int min, int max);
    void setSelection(int sel);
    int getSelection();
    void submenuReplay();
    void submenuRounds();
    void setRounds(int rounds);
    int getRounds();
    void submenuDiceType(int player);
    void setDiceType(int player, int type);
    bool getDiceType(int player);
    void submenuSides();
    void setSides(Dice &obj);

    void submenuGameOver();

protected:
    int selection;
    int rounds;
    bool playerLoadedDice[2];

};

#endif
