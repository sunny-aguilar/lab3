/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "LoadedDie.hpp"
#include <ctime>
#include <vector>
using std::vector;

LoadedDie::LoadedDie() : Die{0} {};
LoadedDie::LoadedDie(int num) : Die{num} {}

int LoadedDie::randomInt() {
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    randomNum = rand() % N + 1;

    int rollNum = Die::randomInt();   // call to over-ridden function in base class

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

    vector<int> diceValues;

    for (int i = 1; i <= N; i++) {
        diceValues.push_back(i);
    }
    for (int i = 0; i < N; i++) {
        std::cout << diceValues[i] << " ";
    }
    std::cout << std::endl;


    return randomNum;
}