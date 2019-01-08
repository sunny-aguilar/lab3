/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This dice class creates an object that has a
**                  member function that returns a random integer from
 *                  1 to N. Includes setter/getters for N. Die class
 *                  is the base class for LoadedDie class.
*********************************************************************/
#include "Die.hpp"


/*********************************************************************
** Description:     no-args default constructor that sets the number
**                  of sides on the die
*********************************************************************/
Die::Die() : N{0} {}

/*********************************************************************
** Description:     1-arg constructor that takes an int parameter to
**                  set the number of sides on the die
*********************************************************************/
Die::Die(int num) : N{num} { setSides(num); }

/*********************************************************************
** Description:     returns a random integer from 1 to N
*********************************************************************/
int Die::randomInt() {
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;
    return randomNum;       // return random integer
}

/*********************************************************************
** Description:     setter that takes an int parameter to set the
**                  sides of N
*********************************************************************/
void Die::setSides(int sides) {
    N = sides;
}

/*********************************************************************
** Description:     getter that returns N
*********************************************************************/
int Die::getSides() {
    return N;
}