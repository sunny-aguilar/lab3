/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "Game.hpp"
#include <iostream>
using std::cout;

void Game::showStartMenu() {
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
         << "Enter 1 to play, enter 2 to exit:\n"
         << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
         << "1. Play Game\n"
         << "2. Exit Game\n"
         << "Enter choice: ";
}