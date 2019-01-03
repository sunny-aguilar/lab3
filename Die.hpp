/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP
#include <iostream>


class Die {
private:
    int N;                  // number of sides on the die
public:
    int randomInt();        // returns a random integer
};

#endif
