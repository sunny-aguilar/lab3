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

Die::Die(int num) : N{num} { N = num; }

int Die::randomInt() {       // returns a random integer
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;
    std::cout << "random integer being returned by Die is " << randomNum << std::endl;
    return randomNum;
}

void Die::setSides(int sides) {
    N = sides;
}

int Die::getSides() {
    return N;
}