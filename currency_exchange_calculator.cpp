#include <iostream>
#include <iomanip> // For setting precision

using namespace std;

int main() {
    // Define variables
    double usdAmount, exchangeRate, convertedAmount;

    // Display a greeting
    cout << "Welcome to the Currency Exchange Calculator!" << endl;

    // Prompt user for the amount in US Dollars
    cout << "Enter the amount in US Dollars you want to convert: ";
    cin >> usdAmount;

    // Prompt user for the current exchange rate
    cout << "Enter the current exchange rate for 1 USD to Euros: ";
    cin >> exchangeRate;

    // Create a 1 line gap for better readability
    cout << endl;

    // Perform the currency conversion
    convertedAmount = usdAmount * exchangeRate;

    // Display the result with precision set to two decimal places
    cout << fixed << setprecision(2);
    cout << usdAmount << " USD is equal to " << convertedAmount << " Euros." << endl;

    return 0;
}




