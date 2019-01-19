/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This dice class creates an object that has a
**                  member function that returns a random integer from
**                  1 to N. Includes setter/getters for N. Die class
**                  is the base class for LoadedDie class.
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