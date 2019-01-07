/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     asdf
**                  asdf
*********************************************************************/
#include "Game.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Game::Game()
    : selection{0}, rounds{0}, diceType{UNSET, UNSET},
    playerOneScore{0}, playerTwoScore{0} {
}

/*********************************************************************
** Description:     shows the start menu
*********************************************************************/
void Game::showStartMenu() {
    cout << "/******************************************/\n"
         << "/              WAR DICE GAME               /\n"
         << "/    Enter 1 to play - Enter 2 to exit     /\n"
         << "/******************************************/\n"
         << "1. Play Game\n"
         << "2. Exit Game\n"
         << ">> ";
}

/*********************************************************************
** Description:     setter sets the selection made in the main menu
*********************************************************************/
void Game::setSelection(int sel) {
    selection = sel;
}

/*********************************************************************
** Description:     getter sgets the selection made in the main menu
*********************************************************************/
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
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
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
        if (!isNotDigit && !tooLong) {
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
         << "Pick between 1 and 1000 rounds\n"
         << ">> ";
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
    cout << "\nEnter the type of die to use for player #" << player
         << "\n1. Normal Dice\n"
         << "2. Loaded Dice\n"
         << ">> ";

}

/*********************************************************************
** Description:     takes a bool parameter to indicate if dice is
**                  loaded
*********************************************************************/
void Game::setDiceType(const int player, const int type) {
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
Dice Game::getDiceType(const int player) {
    if (player <=2 && player >=0) {
        return diceType[player];
    }
    else {
        cout << "Dice type array value is out of bounds!\n";
        return diceType[0];
    }
}

/*********************************************************************
** Description:     asks user for N sides of dice
*********************************************************************/
void Game::submenuSides(const int player) {
    cout << "\nEnter the number of sides on the dice\n"
         << "for player #" << player
         << "\n>> ";
}

/*********************************************************************
** Description:     param takes a dice object to set its sides
**                  called internally, MAKE PRIVATE
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
**                  type of die class object to set the number of sides
*********************************************************************/
void Game::setSidesChosenDice(Die &obj1, LoadedDie &obj2) {
    for (int player = 0; player < 2; player++) {
        submenuSides(player+1);     // internal private member function call
        if (getDiceType(player) == NORMAL) {
            setSides( obj1, validateNumber(3, 20) );
        }
        else if (getDiceType(player) == LOADED) {
            setSides( obj2, validateNumber(3, 20) );
        }
        else {
            cout << "Error setting the number of sides!\n";
        }
    }
}

/*********************************************************************
** Description:     function returns a random int value from either a
**                  normal die or a loaded die depending on the die
 *                  selected by the players. Takes Dice object
 *                  parameters by reference and assigns the resulting
 *                  values to p1RollScore /p2RollScore
*********************************************************************/
int Game::getRollValue(Die &obj1, LoadedDie &obj2, int player)
{
    if (getDiceType(player) == NORMAL) {
        if (player == 0) {
            return obj1.randomInt();
        }
        else if (player == 1) {
            return obj1.randomInt();
        }
    }
    else if (getDiceType(player) == LOADED) {
        if (player == 0) {
            return obj2.randomInt();
        }
        else if (player == 1) {
            return obj2.randomInt();
        }
    }
    else {
        cout << "Error getting roll value!\n";
        return 0;
    }
}

/*********************************************************************
** Description:     parameter takes an int value to set player one
**                  score
*********************************************************************/
void Game::setplayerOneScore(const int score) {
    playerOneScore = score;
}

/*********************************************************************
** Description:     parameter takes an int value to set player two
**                  score
*********************************************************************/
void Game::setplayerTwoScore(const int score) {
    playerTwoScore = score;
}

/*********************************************************************
** Description:     determine the winner and updates the player
**                  scores by adding 1 to the winner's score. The
**                  parameters received are used to compare the roll
**                  value each player rolled and use to determine the
**                  winner
*********************************************************************/
string Game::updatePlayerScore(const int p1Roll, const int p2Roll) {
    if (p1Roll == p2Roll) {
        return "No player wins the round\n";
    }
    else if (p1Roll > p2Roll) {
        addplayerOneScore();
        return "Player one wins the round!\n";
    }
    else if (p1Roll < p2Roll) {
        addplayerTwoScore();
        return "Player two wins the round!\n";
    }
    else {
        cout << "error calculating which player roll is higher!\n";
        return "error calculating which player roll is higher";
    }
}

/*********************************************************************
** Description:     parameter takes an int value to add to player one
**                  score
*********************************************************************/
void Game::addplayerOneScore() {
    playerOneScore += 1;
}

/*********************************************************************
** Description:     parameter takes an int value to add to player two
**                  score
*********************************************************************/
void Game::addplayerTwoScore() {
    playerTwoScore += 1;
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
** Description:    displays detailed results of each round
*********************************************************************/
void Game::submenueReport(string winner, int p1Roll, int p2Roll, int round) {
    cout << "/******************************************/\n"
         << "      Round #" << round << "- Winner & Score Report\n"
         << "/******************************************/\n"
         << ">> "<< winner
         << "Player one rolled a " << p1Roll << endl
         << "Player two rolled a " << p2Roll << endl << endl
         << ">> Player Scores\n"
         << "Player One - " << getplayerOneScore() << endl
         << "Player Two - " << getplayerTwoScore() << endl << endl;

    // switch statement to get value of enum variable
    cout << ">> Type of dice\n";
    for (int player = 0; player < 2; player++) {
        switch ( getDiceType(player) ) {
            case 1:
                cout << "Player One is using a normal dice\n";
                break;
            case 2:
                cout << "Player Two is using a loaded dice\n";
                break;
            default:
                cout << "Error showing dice being used!\n";
        }
    }

    // display this report once all rounds are over to announce winner
    if ( round == getRounds() ) {
        cout << "\n\n>> All rounds are over - and the winner is...\n";
        if ( getplayerOneScore() > getplayerTwoScore() )
            cout << ">> PLAYER ONE!\n";
        else if ( getplayerOneScore() < getplayerTwoScore() )
            cout << ">> PLAYER TWO!\n";
        else
            cout << "GAME IS A TIE!\n";
    }
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
         << "---------  ---------  ---------\n"
         << "Goodbye - Thanks for playing!\n";
}