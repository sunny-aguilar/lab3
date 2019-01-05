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
    // algorithm to taken N int values and change them so that the average
    // output of rolling it out is higher than the die object with the same
    // number of sides
    // Create an array and using the 1-N array and store such that elements up to N
    // are increased as shown in the diagram
    // 1,
    // 22,
    // 333,
    // 4444,
    // 5555,
    // 666666

    vector<int> loadedValues;
    unsigned seed;
    int randomNum;
    seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    // sum of arithmetic sequence is total elements in vector
    int vectorElements = ((N + 1) * N) / 2;

    // computer random number between 1 and vectorElements
    randomNum = rand() % vectorElements + 1;

    // push a total of vectorElements into vector starting with n = 1
    for (int n = 1; n <= vectorElements; n++ ) {
        for ( int count = 1; count <= n; count++) {
            // push back n an n number of times
            loadedValues.push_back( n );
        }
    }

    return loadedValues[randomNum];
}

void LoadedDie::load(int n) {
    vector<int> Narray;
    std::cout << "Size N " << N << std::endl;
    std::cout << "Size n " << n << std::endl;
    if (N >= n) {
        load(n+1);
        std::cout << "recursive n value!\n";
    }
    for (n = 1; n <= N; n++) {

    }

}