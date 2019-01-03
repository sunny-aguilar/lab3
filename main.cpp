/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include <iostream>
#include <ctime>

class Die {
private:
    int N;                  // number of sides on the die
public:
    int randomInt() {       // returns a random integer
        unsigned seed;
        int randomNum;
        seed = static_cast<unsigned int>(time(nullptr));
        srand(seed);
        randomNum = rand() % N + 1;
        return randomNum;
    }
};
class LoadedDie : public Die {

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}