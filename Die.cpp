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

/*********************************************************************
** Description:     no-args default constructor that sets the number
**                  of sides on the die
*********************************************************************/
Die::Die() : N{0} {}

/*********************************************************************
** Description:     1-arg constructor that takes an int parameter to
**                  set the number of sides on the die
*********************************************************************/
Die::Die(int num) : N{num} { N = num; }

/*********************************************************************
** Description:     returns a random integer from 1 to N
*********************************************************************/
int Die::randomInt() {
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;
    return randomNum;
}

/*********************************************************************
** Description:     A
*********************************************************************/
void Die::setSides(int sides) {
    N = sides;
}

/*********************************************************************
** Description:     A
*********************************************************************/
int Die::getSides() {
    return N;
}