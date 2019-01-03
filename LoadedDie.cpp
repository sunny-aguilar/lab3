/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "LoadedDie.hpp"
#include <ctime>

int LoadedDie::randomInt() {
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;
    return randomNum;
}