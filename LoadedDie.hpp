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
public:
    LoadedDie();                        // default constructor
    LoadedDie(int num);                 // 1-arg constructor
    int randomInt();                    // return loaded random integer
};

#endif
