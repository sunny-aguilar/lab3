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
    void validateNumber(int min, int max);
    void setSelection(int sel);
    int getSelection();

protected:
    int selection;

};

#endif
