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
using std::endl;

int main() {
    Die die(10);
    LoadedDie loadedDie;
    cout << "Die " << die.randomInt() << endl;
    cout << "Loaded Die " << loadedDie.randomInt() << endl;
    loadedDie.setN(25);
    loadedDie.getN();

    return 0;
}