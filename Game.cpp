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

Game::Game() : selection{0}, rounds{0}, diceType{UNSET, UNSET}, playerOneScore{0}, playerTwoScore{0} {}

void Game::showStartMenu() {
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
         << "Enter 1 to play - Enter 2 to exit\n"
         << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
         << "1. Play Game\n"
         << "2. Exit Game\n"
         << ">> ";
}

void Game::setSelection(int sel) {
    selection = sel;
}

int Game::getSelection() {
    return selection;
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

            if (amount < min || amount > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return amount;
}

/*********************************************************************
** Description:     asks user to enter the rounds to play
*********************************************************************/
void Game::submenuRounds() {
    cout << "How many rounds do you want to play?\n"
         << "Pick between 1 and 1000 rounds\n";
}

/*********************************************************************
** Description:     takes an int parameter to set the rounds
*********************************************************************/
void Game::setRounds(int rounds) {
    this->rounds = rounds;
}

/*********************************************************************
** Description:     returns the rounds to play
*********************************************************************/
int Game::getRounds() {
    return rounds;
}

/*********************************************************************
** Description:     asks user to enter dice type for each player
*********************************************************************/
void Game::submenuDiceType(int player) {
    cout << "Enter the type of die to use for player #" << player
         << "\n1. Normal Dice\n"
         << "2. Loaded Dice\n";

}

/*********************************************************************
** Description:     takes a bool parameter to indicate if dice is
**                  loaded
*********************************************************************/
void Game::setDiceType(int player, int type) {
    switch (type) {
        case 1:
            diceType[player] = NORMAL;
            break;
        case 2:
            diceType[player] = LOADED;
            break;
        default:
            cout << "Error setting the dice type\n";
    }
}

/*********************************************************************
** Description:     returns player dice type
*********************************************************************/
Dice Game::getDiceType(int player) {
    return diceType[player];
}

/*********************************************************************
** Description:     asks user for N sides of dice
*********************************************************************/
void Game::submenuSides() {
    cout << "Enter the number of sides on the dice\n"
         << ">> ";
}

/*********************************************************************
** Description:     param takes a dice object to set its sides
*********************************************************************/
void Game::setSides(Die &obj, int sides) {
    obj.setSides(sides);
}

/*********************************************************************
** Description:     param takes a loaded dice object to set its sides
*********************************************************************/
void Game::setSides(LoadedDie &obj, int sides) {
    obj.setSides(sides);
}

/*********************************************************************
** Description:     parameters take two objects by reference of each
**                  type of die class to set the number of sides as
**                  appropriate
*********************************************************************/
void Game::setSidesChosenDice(Die &obj1, LoadedDie &obj2) {
    for (int player = 0; player < 2; player++) {
        submenuSides();
        if (getDiceType(player) == NORMAL) {
            setSides( obj1, validateNumber(3, 20) );
            cout << "Sides stored in Die object " << obj1.getSides() << endl;
        }
        else if (getDiceType(player) == LOADED) {
            setSides( obj2, validateNumber(3, 20) );
            cout << "Sides stored in loadedDie object " << obj2.getSides() << endl;
        }
        else {
            cout << "Error setting the number of sides!\n";
        }
    }
}

/*********************************************************************
** Description:     parameter takes an int value to set player one
**                  score
*********************************************************************/
void Game::setplayerOneScore(int score) {
    playerOneScore = score;
}

/*********************************************************************
** Description:     parameter takes an int value to set player two
**                  score
*********************************************************************/
void Game::setplayerTwoScore(int score) {
    playerTwoScore = score;
}

/*********************************************************************
** Description:     parameter takes an int value to add to player one
**                  score
*********************************************************************/
void Game::addplayerOneScore(int score) {
    playerOneScore += score;
}

/*********************************************************************
** Description:     parameter takes an int value to add to player two
**                  score
*********************************************************************/
void Game::addplayerTwoScore(int score) {
    playerTwoScore += score;
}

/*********************************************************************
** Description:    gets the score of player one
*********************************************************************/
int Game::getplayerOneScore() {
    return playerOneScore;
}

/*********************************************************************
** Description:    gets the score of player two
*********************************************************************/
int Game::getplayerTwoScore() {
    return playerTwoScore;
}

/*********************************************************************
** Description:     asks user if they want to play again
*********************************************************************/
void Game::submenuReplay() {
    cout << "1. Play again\n"
         << "2. End game\n";
}

/*********************************************************************
** Description:     thanks user for playing the game
*********************************************************************/
void Game::submenuGameOver() {
    cout << "---------  ---------  ---------\n"
         << "| o     |  | o   o |  | o   o |\n"
         << "|   o   |  |       |  |   o   |\n"
         << "|     o |  | o   o |  | o   o |\n"
         << "---------  ---------  ---------\n";

    cout << "Goodbye - Thanks for playing!\n";
}