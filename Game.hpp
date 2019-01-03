/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

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
    void submenuGameOver();

protected:
    int selection;
    int rounds;

};

#endif
