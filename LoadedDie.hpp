/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie : public Die {
private:

public:
    LoadedDie() : N{0} {};
    LoadedDie(int num) { N = num; }

};

#endif
