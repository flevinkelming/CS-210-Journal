/*
    Author: Kevin Fleming
    Date: 04/09/2024
    Purpose: This program allows a user to see how their investments
        will grow over time
*/

#include "investment_report.h"
#include "user_interface.h"

int main() {
    // Variables to store user input
    double initialInvestment, monthlyDeposit, annualInterest;
    int years;

    // Get user input for reporting
    getUserInput(initialInvestment, monthlyDeposit, annualInterest, years);

    // Create reports based on user input and ouput results
    InvestmentReport report(initialInvestment, monthlyDeposit, annualInterest, years);
    report.generateReports();
    report.printReports();

    return 0;
}
