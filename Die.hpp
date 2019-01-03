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
protected:
    int N;                  // number of sides on the die

public:
    Die() : N{0} {}
    Die(int num) { N = num; }
    int randomInt();        // returns a random integer
    void setN(int n) { N = n;}
    void getN() { std::cout << N << std::endl; }
};

#endif
