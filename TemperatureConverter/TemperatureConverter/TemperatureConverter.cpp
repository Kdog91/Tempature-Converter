#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    // Input and Output file names
    string inputFileName = "FahrenheitTemperature.txt";
    string outputFileName = "CelsiusTemperature.txt";

    // File stream objects
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Check if input file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open the file " << inputFileName << endl;
        return 1;  // Exit with error
    }

    // Check if output file opened successfully
    if (!outputFile) {
        cerr << "Error: Could not open the file " << outputFileName << endl;
        return 1;  // Exit with error
    }

    // Variables to store city name and temperature in Fahrenheit
    string city;
    int fahrenheitTemperature;

    // Process each line in the input file
    while (inputFile >> city >> fahrenheitTemperature) {
        // Convert temperature from Fahrenheit to Celsius
        double celsiusTemperature = fahrenheitToCelsius(fahrenheitTemperature);

        // Write the city and its temperature in Celsius to the output file
        outputFile << city << " " << celsiusTemperature << endl;
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    cout << "Conversion completed. Check the " << outputFileName << " for results." << endl;

    return 0;  // Exit the program successfully
}
