#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <string>

void displayCenteredTitle(const std::string &title, int width);
void getUserInput(
    double &initialInvestment,
    double &monthlyDeposit,
    double &annualInterest,
    int &years
);

#endif // USER_INTERFACE_H
