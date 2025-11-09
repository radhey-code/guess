#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "\n\t\t\t\t\t\t Welcome to \n\t\t\t\t\t   Guess The Number game!!" << endl;
    cout << "\n\t\t\t\t\t\tINSTRUCTIONS" << endl;
    cout << "\t\t\t\tYou have to guess a number between 1 and 100."
         << "\n\t\t\tYou'll get limited chances based on the difficulty level you choose." << endl;

    while (true) {
        cout << "\nDifficulty Levels\n";
        cout << "1 for easy level!\n";
        cout << "2 for medium-level!\n";
        cout << "3 for difficult level!\n";
        cout << "0 for ending the game!\n" << endl;

        // select the level of difficulty
        int level;
        cout << "Enter the difficulty level number: ";
        cin >> level;

        // to end the game
        if (level == 0) {
            cout << "Thanks for playing! Goodbye!" << endl;
            exit(0);
        }

        else if (level < 0 || level > 3) {
            cout << "Kindly select between (0,1,2,3)" << endl;
            continue;
        }

        // generating the random number
        srand(time(0));
        int randomNumber = (rand() % 100) + 1;
        int guess;

        int leftChance;

        if (level == 1) leftChance = 7;
        else if (level == 2) leftChance = 5;
        else if (level == 3) leftChance = 3;

        cout << "\nYou have " << leftChance << " chances to find the random number between 1 and 100." << endl;

        for (int i = 1; i <= leftChance; i++) {
            cout << "\nEnter your guess: ";
            cin >> guess;

            if (guess == randomNumber) {
                cout << "\n congratulations! You guessed the right number!\n";
                break;
            }
            else if (guess > randomNumber) {
                cout << guess << " is greater than the random number.\n";
            }
            else {
                cout << guess << " is less than the random number.\n";
            }

            if (i == leftChance) {
                cout << "\n Better luck next time! The number was " << randomNumber << "." << endl;
            }
        }
    }

    return 0;
}

