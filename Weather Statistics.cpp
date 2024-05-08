#include <iostream>
using namespace std;

// Structure to store weather data for a month
struct WeatherData {
    double totalRainfall;
    double highTemp;
    double lowTemp;
    double avgTemp;
};

// Function to validate temperature entry
double validateTemperatureInput(const char* tempType) {
    double temperature;
    do {
        cout << "Enter the " << tempType << " temperature (-100 to 140 degrees Fahrenheit): ";
        cin >> temperature;
        if (temperature < -100 || temperature > 140) {
            cout << "Temperature should be within the range of -100 to 140 degrees Fahrenheit.\n";
        }
    } while (temperature < -100 || temperature > 140);
    return temperature;
}

int main() {
    WeatherData year[12];  // Array to hold data for an entire year

    // Input weather data for each month
    for (int i = 0; i < 12; ++i) {
        cout << "\nEnter data for Month " << i + 1 << ":\n";
        year[i].totalRainfall = 0; // Initialize total rainfall for the month

        // Input and validate temperature data
        year[i].highTemp = validateTemperatureInput("high");
        year[i].lowTemp = validateTemperatureInput("low");

        // Calculate average temperature
        year[i].avgTemp = (year[i].highTemp + year[i].lowTemp) / 2;

        cout << "Enter the total rainfall for the month: ";
        cin >> year[i].totalRainfall;
    }

    // Calculate yearly statistics
    double yearlyTotalRainfall = 0;
    double totalMonthlyAvgTemp = 0;
    double highestTemp = -100;
    double lowestTemp = 140;
    int highestTempMonth = 0, lowestTempMonth = 0;

    for (int i = 0; i < 12; ++i) {
        yearlyTotalRainfall += year[i].totalRainfall;
        totalMonthlyAvgTemp += year[i].avgTemp;

        // Find highest temperature and its month
        if (year[i].highTemp > highestTemp) {
            highestTemp = year[i].highTemp;
            highestTempMonth = i + 1;
        }

        // Find lowest temperature and its month
        if (year[i].lowTemp < lowestTemp) {
            lowestTemp = year[i].lowTemp;
            lowestTempMonth = i + 1;
        }
    }

    // Output the calculated statistics
    cout << "\nStatistics for the year:\n";
    cout << "Average Monthly Rainfall: " << yearlyTotalRainfall / 12 << " inches\n";
    cout << "Total Yearly Rainfall: " << yearlyTotalRainfall << " inches\n";
    cout << "Highest Temperature (" << highestTemp << "F) occurred in Month " << highestTempMonth << endl;
    cout << "Lowest Temperature (" << lowestTemp << "F) occurred in Month " << lowestTempMonth << endl;
    cout << "Average of Monthly Average Temperatures: " << totalMonthlyAvgTemp / 12 << "F\n";

    return 0;
}