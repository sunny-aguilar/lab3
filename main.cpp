/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "Die.hpp"
#include "LoadedDie.hpp"
#include <iostream>
using std::cout;

int main() {
    Die die;
    LoadedDie loadedDie;
    cout << loadedDie.randomInt();

    return 0;
}