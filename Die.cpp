/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "Die.hpp"
#include <ctime>
#include <vector>
using std::vector;

Die::Die() : N{0} {}

/*********************************************************************
** Description:     A
*********************************************************************/
Die::Die(int num) : N{num} { N = num; }

/*********************************************************************
** Description:     A
*********************************************************************/
int Die::randomInt() {       // returns a random integer
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;
    return randomNum;
}

void Die::setSides(int sides) {
    N = sides;
}

int Die::getSides() {
    return N;
}