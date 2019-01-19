/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     This class is a subclass of the Die class. This
**                  dice subclass creates an object that has a
**                  member function that returns a random integer from
**                  1 to N (over-rides base class member function).
**                  However, it is loaded because the odds of rolling
**                   a higher value are greater.
*********************************************************************/
#include "LoadedDie.hpp"

/*********************************************************************
** Description:     no-args default constructor that also calls the
**                  base class no-args constructor0
*********************************************************************/
LoadedDie::LoadedDie() : Die{} {};

/*********************************************************************
** Description:     1-arg constructor that calls the base class 1-arg
**                  constructors
*********************************************************************/
LoadedDie::LoadedDie(int num) : Die{num} {}

/*********************************************************************
** Description:     this function returns an integer from 1 to N where
**                  the average output of rolling it several times is
**                  higher than that of a Die object with the same
**                  number of sides. Over-rides base class member
**                  function Algorithm explanation below.
*********************************************************************/
int LoadedDie::randomInt() {
    // algorithm: create a vector with a total number of elements that
    // is equal to the sum of the arithmetic sequence of N i.e., elements
    // in vector should be equal to = ((N + 1) * N) / 2. The values
    // pushed into the vector starts with one all they way up to N,
    // i.e.:
    // 1,       push 1, once
    // 22,      push 2, twice
    // 333,     push 3, three times
    // 4444,    push 4, four times
    // 55555,   push 5, five times
    // 666666   push 6, six times

    // create vector to hold values
    vector<int> loadedValues;

    // hold an unbiased, random value from 1 to N
    int randomNum;

    // vector elements is equal to the sum of an arithmetic sequence N
    int vectorElements = ((N + 1) * N) / 2;

    // compute random number between 1 and vectorElements
    randomNum = rand() % vectorElements;

    // push a total of vectorElements into vector starting with n = 1
    for (int n = 1; n <= N; n++ ) {
        for ( int count = 1; count <= n; count++) {
            loadedValues.push_back( n );
        }
        std::cout << std::endl;
    }

    // return a random integer from vector
    return loadedValues[randomNum];
}