/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "Die.hpp"
#include <ctime>
#include <cstdlib>

int Die::randomInt() {       // returns a random integer
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;
    return randomNum;
}