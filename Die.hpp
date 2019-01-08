/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

#include <iostream>
#include <ctime>
#include <vector>
using std::vector;

class Die {
public:
    Die();                          // default constructor
    Die(int num);                   // 1-arg constructor
    int randomInt();                // returns a random integer
    void setSides(int sides);       // setter that sets die sides
    int getSides();                 // getter that returns die sides

protected:
    int N;                          // number of sides on the die
};

#endif
