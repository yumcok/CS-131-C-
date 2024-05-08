#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// The ability to document monetary exchanges

void recordTransaction() {
    ofstream file("finances.txt", ios::app); // Open file in append mode
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string date, description, type;
    double amount;

    cout << "Enter transaction details (date, description, amount, type): ";
    cin >> date >> description >> amount >> type;

    file << date << "," << description << "," << amount << "," << type << endl;
    
    file.close();
    cout << "Transaction recorded successfully." << endl;
}

// The ability to see recorded transactions

void displayTransactions() {
    ifstream file("finances.txt");
    if (!file.is_open()) {
        cerr << "No transactions recorded yet." << endl;
        return;
    }

    cout << "Date\tDescription\tAmount\tType" << endl;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            cout << token << "\t";
        }
        cout << endl;
    }
    file.close();
}

// Main function
int main() {
    int choice;
    do {
        cout << "\nPersonal Finance Recorder\n";
        cout << "1. Record a Transaction\n";
        cout << "2. Display Recorded Transactions\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                recordTransaction();
                break;
            case 2:
                displayTransactions();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}