/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This class is a subclass of the Die class. This
**                  dice subclass creates an object that has a
**                  member function that returns a random integer from
**                  1 to N (over-rides base class member function).
**                  However, it is loaded because the odds of rolling
**                  a higher value are greater. This class inherits
**                  publicly from its base class.
*********************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"
#include <ctime>

class LoadedDie : public Die {
public:
    LoadedDie();                        // default constructor
    LoadedDie(int num);                 // 1-arg constructor
    int randomInt();                    // return loaded random integer
};

#endif