#ifndef INVESTMENT_REPORT_H
#define INVESTMENT_REPORT_H

#include <vector>
#include <string>

// Used by InvestmentReport for reporting
struct YearlyReport {
    int year;
    double endingBalance;
    double earnedInterest;

    YearlyReport(int y, double eb, double ei) : year(y), endingBalance(eb), earnedInterest(ei) {}
};

// Handles the calculation of investment growth and printing the reports
class InvestmentReport {
public:
    InvestmentReport(double initialAmount, double monthlyDeposit, double annualRate, int years);
    void generateReports();
    void printReports() const;

private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int investmentYears;
    std::vector<YearlyReport> reportWithoutDeposits;
    std::vector<YearlyReport> reportWithDeposits;

    void generateReportWithoutDeposits();
    void generateReportWithDeposits();
    void printReportHeader(const std::string &title) const;
    void printReportData(const std::vector<YearlyReport> &report) const;
    std::string formatCurrency(double amount) const;
};

#endif // INVESTMENT_REPORT_H
