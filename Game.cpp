/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Jan 2019
** Description:     Game class implements the dice-rolling game. It
**                  sets the game elements such as showing menus,
**                  validating user data, as well as keeping score.
**                  The game class is not derived from and it is not
**                  derived. Internal functions are labeled as private.
**                  The class protected variables are used to set the
**                  games parameters such as rounds to play and type of
**                  dice to use.
*********************************************************************/
#include "Game.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Game::Game() :
    selection{0},
    rounds{0},
    diceType{UNSET, UNSET},
    playerOneScore{0},
    playerTwoScore{0} {
}

/*********************************************************************
** Description:     this function is called from main to get the game
**                  started. Constant game variables are used to set
**                  the parameters of the game. This function mainly
**                  controls the game flow such as calling the
**                  functions that set the game up, play the game,
**                  and control whether the game continues or ends.
**                  This is done by calling the appropriate functions.
*********************************************************************/
void Game::playGame() {
    // constant game variables
    const int MIN_VAL = 1, MAX_VAL = 2;
    const int MIN_ROUNDS = 1, MAX_ROUNDS = 1000;
    const int MIN_SIDES = 3, MAX_SIDES = 20;

    // show start menu
    showStartMenu();
    setSelection(validateNumber(MIN_VAL,MAX_VAL));

    if (getSelection() == 1) {
        // user plays the game
        cout << "\nStarting Game\n\n";
        do {
            // prompt user to enter rounds and validate it
            submenuRounds();
            setRounds( validateNumber(MIN_ROUNDS, MAX_ROUNDS) );

            //  ask user the type of die for each player
            for (int player = 0; player < 2; player++) {
                submenuDiceType(player+1);
                setSelection( validateNumber(1, 2) );
                setDiceType( player, getSelection() );
            }

            // ask user for number of sides for dice of both players
            setSidesChosenDice(dice, loadedDice, MIN_SIDES, MAX_SIDES);

            // loop through the rounds to play
            rollDice();
        } while (replay()); // ask user if they want to play again

        // game has ended message
        cout << "Game finished\n";
    }
    else if (getSelection() == 2) {
        // user quit the program in the main menu and game quits
        submenuGameOver();
    }
    else {
        // error processing main menu input
        cout << "Error processing your request!\n";
    }
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
** Description:     gets the selection made in the main menu
*********************************************************************/
int Game::getSelection() {
    return selection;
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable. Checks user input
**                  for non-digit characters, number of digits entered,
**                  and if within valid range.
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
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

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
** Description:     prompts user to enter the rounds to play
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
** Description:     prompts user to enter dice type for each player
*********************************************************************/
void Game::submenuDiceType(int player) {
    cout << "\nEnter the type of die to use for player #" << player
         << "\n1. Normal Dice\n"
         << "2. Loaded Dice\n"
         << ">> ";
}

/*********************************************************************
** Description:     takes in a player parameter and dice type in order
**                  to set up the dice that each player will have
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
** Description:     takes in a player parameter and returns the
**                  player's dice type
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
** Description:     asks user for N sides of dice. Receives parameters
**                  that identify the player it is asking for display
**                  purposes.
*********************************************************************/
void Game::submenuSides(int minSides, int maxSides) {
    cout << "\nEnter the number of sides on the dice\n" << "(min "
         << minSides << " max " << maxSides
         << ")\n>> ";
}

/*********************************************************************
** Description:     param takes a dice object to set its N sides
**                  called internally by setSidesChosenDice(...
*********************************************************************/
void Game::setSides(Die &obj, int sides) {
    obj.setSides(sides);
}

/*********************************************************************
** Description:     param takes a loaded dice object to set its N
**                  sides, called internally by setSidesChosenDice(...
*********************************************************************/
void Game::setSides(LoadedDie &obj, int sides) {
    obj.setSides(sides);
}

/*********************************************************************
** Description:     parameters take two objects by reference of each
**                  type of die class object to set the number of sides
*********************************************************************/
void Game::setSidesChosenDice(Die &obj1, LoadedDie &obj2, int minSides, int maxSides) {
    submenuSides(minSides, maxSides);
    int selection = validateNumber(minSides, maxSides);
    for (int player = 0; player < 2; player++) {
        // internal private member function call that displays menu
        // asking user to enter total sides on dice

        // check each player's chosen dice type and set its sides
        if (getDiceType(player) == NORMAL) {
            setSides( obj1, selection );
        }
        else if (getDiceType(player) == LOADED) {
            setSides( obj2, selection);
        }
        else {
            cout << "Error setting the number of sides!\n";
        }
    }
}

/*********************************************************************
** Description:     this function rolls the dice repeating each round
**                  to be played in a for-loop, assigns the scores
**                  rolled, and calls another function to show the
**                  score report.
*********************************************************************/
void Game::rollDice() {
    for (int round = 0; round < getRounds(); round++) {

        // roll dice for player 1 and player 2 and assign values to variables
        int p1RollScore = 0, p2RollScore = 0;
        p1RollScore = getRollValue(dice, loadedDice, 0);
        p2RollScore = getRollValue(dice, loadedDice, 1);

        // update winner score
        std::string winner;
        winner = updatePlayerScore(p1RollScore, p2RollScore);

        // display game results after each round
        submenuReport(winner, p1RollScore, p2RollScore, round+1);

        // end of round pause to view game report
        cout << "\nHit [Enter] to continue\n";
        cin.get();
    }
}

/*********************************************************************
** Description:     function returns a random int value from either a
**                  normal die or a loaded die depending on the die
**                  being used by the players. Takes Dice object
**                  parameters by reference and returns the resulting
**                  value.
*********************************************************************/
int Game::getRollValue(Die &obj1, LoadedDie &obj2, int player) {
    // return a random integer from a normal dice
    if (getDiceType(player) == NORMAL) {
        if (player == 0) {
            return obj1.randomInt();
        }
        else if (player == 1) {
            return obj1.randomInt();
        }
    }
    // return a random but loaded integer
    else if (getDiceType(player) == LOADED) {
        if (player == 0) {
            return obj2.randomInt();
        }
        else if (player == 1) {
            return obj2.randomInt();
        }
    }
    else {
        // error message if error in getting dice type
        cout << "Error getting roll value!\n";
        return 0;
    }
    
    // unused return value
    return 0;
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
**                  winner.
*********************************************************************/
string Game::updatePlayerScore(const int p1Roll, const int p2Roll) {
    if (p1Roll == p2Roll) {
        // tie game, no one scores
        return "No player wins the round\n";
    }
    else if (p1Roll > p2Roll) {
        // player 1 wins, increase their score
        addplayerOneScore();
        return "Player one wins the round!\n";
    }
    else if (p1Roll < p2Roll) {
        // player 2 wins, increase their score
        addplayerTwoScore();
        return "Player two wins the round!\n";
    }
    else {
        // error updating scores
        cout << "error calculating which player roll is higher!\n";
        return "error calculating which player roll is higher";
    }
}

/*********************************************************************
** Description:     Increases player one score by 1. Internal class
**                  function.
*********************************************************************/
void Game::addplayerOneScore() {
    playerOneScore += 1;
}

/*********************************************************************
** Description:     Increases player two score by 1. Internal class
**                  function.
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
** Description:     displays detailed results of each round including
**                  the final round
*********************************************************************/
void Game::submenuReport(string winner, int p1Roll, int p2Roll, int round) {
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
                cout << "Player One is using a normal dice with " << dice.getSides() << " sides\n";
                break;
            case 2:
                cout << "Player Two is using a loaded dice with " << loadedDice.getSides() << " sides\n";
                break;
            default:
                cout << "Error showing dice being used!\n";
        }
    }

    // display this report once all rounds are over to announce winner
    if ( round == getRounds() ) {
        cout << "\n\n>> All rounds are over - and the winner is...\n";
        if ( getplayerOneScore() > getplayerTwoScore() ) {
            cout << ">> PLAYER ONE!\n";
        }
        else if ( getplayerOneScore() < getplayerTwoScore() ) {
            cout << ">> PLAYER TWO!\n";
        }
        else {
            cout << "GAME IS A TIE!\n";
        }
    }
}

/*********************************************************************
** Description:     asks user if they want to play again and returns
**                  bool value to play or quit
*********************************************************************/
bool Game::replay() {
    bool playAgain;
    submenuReplay();
    setSelection( validateNumber(1, 2) );
    if (getSelection() == 2) {
        // control statement to play again
        submenuGameOver();
        playAgain = false;
    }
    else {
        playAgain = true;
        setplayerOneScore(0);
        setplayerTwoScore(0);
    }
    return playAgain;
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