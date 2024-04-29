#include "investment_report.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Constructor for the InvestmentReport class
InvestmentReport::InvestmentReport(double initialAmount, double monthlyDeposit, double annualRate, int years)
    : initialInvestment(initialAmount), monthlyDeposit(monthlyDeposit),
      annualInterestRate(annualRate), investmentYears(years) {}

// Private method to generate a report without additional monthly deposits
void InvestmentReport::generateReportWithoutDeposits()
{
    double currentBalance = initialInvestment;
    reportWithoutDeposits.clear();

    for (int year = 1; year <= investmentYears; ++year)
    {
        double yearlyInterest = 0;

        for (int month = 1; month <= 12; ++month)
        {
            double monthlyInterest = currentBalance * (annualInterestRate / 100) / 12;
            yearlyInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        reportWithoutDeposits.push_back(YearlyReport(year, currentBalance, yearlyInterest));
    }
}

// Private method to generate a report with additional monthly deposits
void InvestmentReport::generateReportWithDeposits()
{
    double currentBalance = initialInvestment;
    reportWithDeposits.clear();

    for (int year = 1; year <= investmentYears; ++year)
    {
        double yearlyInterest = 0;

        for (int month = 1; month <= 12; ++month)
        {
            double monthlyInterest = (currentBalance + monthlyDeposit) * (annualInterestRate / 100) / 12;
            yearlyInterest += monthlyInterest;
            currentBalance += monthlyInterest + monthlyDeposit;
        }

        reportWithDeposits.push_back(YearlyReport(year, currentBalance, yearlyInterest));
    }
}

// Public method to generate both reports
void InvestmentReport::generateReports()
{
    generateReportWithoutDeposits();
    generateReportWithDeposits();
}

// Private method to print the header for a report
void InvestmentReport::printReportHeader(const string &title) const
{
    cout << string(60, '=') << endl;
    cout << title << endl;
    cout << string(60, '=') << endl;
    cout << setw(10) << left << "Year"
         << setw(20) << "Year End Balance"
         << "Year End Earned Interest" << endl;
    cout << string(60, '-') << endl;
}

// Private method to print the data for a report
void InvestmentReport::printReportData(const vector<YearlyReport> &report) const
{
    for (size_t i = 0; i < report.size(); ++i)
    {
        const YearlyReport &entry = report[i];
        cout << setw(10) << left << entry.year
             << setw(20) << formatCurrency(entry.endingBalance)
             << formatCurrency(entry.earnedInterest) << endl;
    }

    cout << endl; // Add a blank line after the report
}

// Public method to print both reports
void InvestmentReport::printReports() const
{
    printReportHeader("Balance and Interest Without Additional Monthly Deposits");
    printReportData(reportWithoutDeposits);

    printReportHeader("Balance and Interest With Additional Monthly Deposits");
    printReportData(reportWithDeposits);
}

// Helper function to format a double value as a currency string
string InvestmentReport::formatCurrency(double amount) const
{
    stringstream stream;
    stream << fixed << setprecision(2) << "$" << amount;
    return stream.str();
}
