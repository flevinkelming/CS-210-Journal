#include "user_interface.h"
#include <iostream>
#include <limits>

using namespace std;

// Implementation of displayCenteredTitle and getUserInput functions...

// A function to display a centered title within a border of '*' characters
void displayCenteredTitle(const string &title, int width)
{
    string border(width - 2, '*');          // Create a string of '*' characters for the border
    int titleWidth = title.length() + 4;    // Add 4 for the spaces and asterisks around the title
    int padding = (width - titleWidth) / 2; // Calculate padding for the title

    // Display the top border
    cout << border << endl;

    // Display the centered title
    cout << string(padding, '*') << " " << title << " " << string(padding, '*') << endl;
}

// A function to get the user input to use in investment calculations
void getUserInput(
    double &initialInvestment,
    double &monthlyDeposit,
    double &annualInterest,
    int &years)
{
    // Display the input screen with centered title
    displayCenteredTitle(" Data Input ", 32);

    cout << endl; // Visual spacing

    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Annual Interest: %";
    cin >> annualInterest;

    cout << "Number of Years: ";
    cin >> years;

    cout << "\nPress any key to continue . . . ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    cin.get();                                                     // Pause for user to press a key

    cout << endl; // Visual spacing
};