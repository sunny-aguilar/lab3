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
public:
    Die();
    Die(int num);
    int randomInt();        // returns a random integer

protected:
    int N;                  // number of sides on the die
};

#endif
