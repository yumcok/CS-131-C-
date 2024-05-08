#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Greet the user and introduce the billing system
    cout << "Welcome to the Electricity Billing System Simulation!" << endl;

    // Prompt the user to enter the number of months
    int numMonths;
    cout << "Enter the number of months for which you want to calculate the electricity bill: ";
    cin >> numMonths;

    // Validate the input for the number of months
    while (numMonths <= 0) {
        cout << "Please enter a positive number of months: ";
        cin >> numMonths;
    }

    double totalBill = 0;

    // Loop for each month
    for (int month = 1; month <= numMonths; ++month) {
        // Ask the user to input the number of units consumed
        double unitsConsumed;
        cout << "\nEnter the number of units consumed for Month " << month << ": ";
        cin >> unitsConsumed;

        // Validate the input for units consumed
        while (unitsConsumed < 0) {
            cout << "Please enter a non-negative number of units: ";
            cin >> unitsConsumed;
        }

        // Calculate the bill based on the tiered rate system
        double baseCharge = 0;
        double rate1 = 0.50, rate2 = 0.75, rate3 = 1.25;
        double serviceCharge = 15;
        double taxRate = 0.10;

        if (unitsConsumed <= 100) {
            baseCharge = unitsConsumed * rate1;
        } else if (unitsConsumed <= 300) {
            baseCharge = 100 * rate1 + (unitsConsumed - 100) * rate2;
        } else {
            baseCharge = 100 * rate1 + 200 * rate2 + (unitsConsumed - 300) * rate3;
        }

        // Calculate total monthly bill
        double monthlyBill = baseCharge + serviceCharge;
        double tax = monthlyBill * taxRate;
        monthlyBill += tax;

        // Display the monthly bill
        cout << fixed << setprecision(2);
        cout << "\nMonthly Bill for Month " << month << ": $" << monthlyBill << endl;

        // Update the total bill
        totalBill += monthlyBill;
    }

    // Calculate and display the average bill
    double averageBill = totalBill / numMonths;
    cout << fixed << setprecision(2);
    cout << "\nAverage Monthly Bill over " << numMonths << " months: $" << averageBill << endl;

    return 0;
}
