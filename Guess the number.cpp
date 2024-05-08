#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Constants
    const int lowerBound = 1;
    const int upperBound = 10;

    // Variables
    int secretNumber = rand() % upperBound + lowerBound;
    int userGuess;
    int attempts = 0;
    char playAgain;

    do {
        // Start of a new game round
        cout << "Welcome to the Number Guessing Game!" << endl;

        do {
            // Get user input
            cout << "Enter your guess between " << lowerBound << " and " << upperBound << ": ";
            while (!(cin >> userGuess) || userGuess < lowerBound || userGuess > upperBound) {
                cout << "Invalid input. Please enter a valid guess between " << lowerBound << " and " << upperBound << ": ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // Provide feedback
            attempts++;
            if (userGuess == secretNumber) {
                cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            } else if (userGuess < secretNumber) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Too high! Try again." << endl;
            }

        } while (userGuess != secretNumber);

        // Ask the user if they want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        // Reset variables for a new game round
        secretNumber = rand() % upperBound + lowerBound;
        attempts = 0;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye." << endl;

    return 0;
}
