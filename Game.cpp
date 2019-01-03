/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "Game.hpp"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

void Game::showStartMenu() {
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
         << "Enter 1 to play - Enter 2 to exit\n"
         << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
         << "1. Play Game\n"
         << "2. Exit Game\n"
         << ">> ";
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Game::validateNumber(int min, int max) {
    char choice[100];
    int amount = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();


    do {
//        cout << "Enter an integer between " <<  min << " and " << max << endl;
        cin.getline(choice, 100);

        // check if length is greater than 3
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (int i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit)
            cout << "enter only digits!\n";

        // check if characters entered are within range
        notInRange = false;
        if (isNotDigit == false && tooLong == false) {
            convert.clear();
            convert << choice;
            convert >> amount;

            if (amount >= min && amount <= max) {
                cout << "You entered " << amount << endl;
            }
            else {
                notInRange = true;
                cout << "enter a number between 1 or 2!\n";
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return amount;
}