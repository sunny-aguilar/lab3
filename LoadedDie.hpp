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
    LoadedDie() : Die{0} {};
    LoadedDie(int num) : Die{num} {}
    int randomInt();
};

#endif
