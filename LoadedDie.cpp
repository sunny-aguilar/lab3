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
    std::cout << " score rolled is " << randomNum << std::endl;
    int rollNum = Die::randomInt();   // call to over-ridden function in base class

//    Create an array and using the 1-N array and store such that elements up to N
//    are increased as shown in the diagram
//    1,
//    22,
//    333,
//    4444,
//    5555,
//    666666



//      I dont think i'll use this code below
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

    vector<int> diceValues, loadedValues;

    // store N int values from 1 to N into a vector
    for (int i = 1; i <= N; i++) {
        diceValues.push_back(i);
    }

    // algorithm to taken N int values and change them so that the average
    // output of rolling it out is higher than the die object with the same
    // number of sides
    for (int n = 1; n <= N; n++ ) {
        for ( int x = 1; x <= n; x++) {
            loadedValues.push_back( n );
        }
    }


    // display N int values in vector
    std::cout << "Displaying loaded vector values:  ";
    for (int n = 0; n < N; n++) {
        std::cout << loadedValues[n] << " ";
    }
    std::cout << std::endl;


    return randomNum;
}

//int LoadedDie::load(int n) {
//    std::cout << "Size N " << N << std::endl;
//    std::cout << "Size n " << n << std::endl;
//    if (N >= n) {
//        load(n+1);
//        std::cout << "recursive n value!\n";
//    }


//    return n;
//}