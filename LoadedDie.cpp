/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "LoadedDie.hpp"
#include <ctime>

LoadedDie::LoadedDie() : Die{0} {};
LoadedDie::LoadedDie(int num) : Die{num} {}

int LoadedDie::randomInt() {
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;

    Die::randomInt();   // call to over-riden function in base class

//    if (rollValue >= 0 && rollValue <=25) {
//
//    }
//    else if (rollValue > 25 && rollValue <= 50) {
//
//    }
//    else if (rollValue > 50 && rollValue <= 75) {
//
//    }
//    else if (rollValue > 75) {
//
//    }

    return randomNum;
}