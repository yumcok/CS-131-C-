#include <iostream>
#include <cstdlib>
#include <ctime>

const int MONTH_DAYS = 30;

// Function to populate the array with random stock prices
void initializeData(double prices[]) {
    srand(time(nullptr)); // Seed the random number generator
    for (int i = 0; i < MONTH_DAYS; ++i) {
        prices[i] = 50 + (rand() % (150 - 50 + 1)); // Generate random prices between 50 and 150
    }
}

// Function to display all stock prices
void displayPrices(const double prices[]) {
    std::cout << "Stock Prices for the Month:\n";
    for (int i = 0; i < MONTH_DAYS; ++i) {
        std::cout << "Day " << i + 1 << ": $" << prices[i] << std::endl;
    }
}

// Function to find and display the highest stock price
void findAndDisplayHighest(const double prices[]) {
    double highest = prices[0];
    for (int i = 1; i < MONTH_DAYS; ++i) {
        if (prices[i] > highest) {
            highest = prices[i];
        }
    }
    std::cout << "Highest Stock Price for the Month: $" << highest << std::endl;
}

// Function to find and display the lowest stock price
void findAndDisplayLowest(const double prices[]) {
    double lowest = prices[0];
    for (int i = 1; i < MONTH_DAYS; ++i) {
        if (prices[i] < lowest) {
            lowest = prices[i];
        }
    }
    std::cout << "Lowest Stock Price for the Month: $" << lowest << std::endl;
}

// Function to calculate and display the average stock price
void calculateAndDisplayAverage(const double prices[]) {
    double total = 0;
    for (int i = 0; i < MONTH_DAYS; ++i) {
        total += prices[i];
    }
    double average = total / MONTH_DAYS;
    std::cout << "Average Stock Price for the Month: $" << average << std::endl;
}

// Function to find and display the day(s) with the largest price drop
void findAndDisplayLargestDrop(const double prices[]) {
    double largestDrop = 0;
    int dropDay = -1;
    for (int i = 1; i < MONTH_DAYS; ++i) {
        double drop = prices[i - 1] - prices[i];
        if (drop > largestDrop) {
            largestDrop = drop;
            dropDay = i;
        }
    }
    if (dropDay != -1) {
        std::cout << "Day(s) with the Largest Price Drop: Day " << dropDay << std::endl;
    } else {
        std::cout << "No significant price drop compared to the previous day.\n";
    }
}

// Function to find and display the day(s) with the largest price gain
void findAndDisplayLargestGain(const double prices[]) {
    double largestGain = 0;
    int gainDay = -1;
    for (int i = 1; i < MONTH_DAYS; ++i) {
        double gain = prices[i] - prices[i - 1];
        if (gain > largestGain) {
            largestGain = gain;
            gainDay = i;
        }
    }
    if (gainDay != -1) {
        std::cout << "Day(s) with the Largest Price Gain: Day " << gainDay << std::endl;
    } else {
        std::cout << "No significant price gain compared to the previous day.\n";
    }
}

int main() {
    double prices[MONTH_DAYS];

    // Initialize data
    initializeData(prices);

    // Display all stock prices
    displayPrices(prices);

    // Analyze prices
    findAndDisplayHighest(prices);
    findAndDisplayLowest(prices);
    calculateAndDisplayAverage(prices);

    // Analyze price fluctuations
    findAndDisplayLargestDrop(prices);
    findAndDisplayLargestGain(prices);

    return 0;
}