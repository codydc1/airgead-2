#include <iostream>
#include <string_view>
#include <vector>
#include <iomanip>
#include "Banking.h"
#include "Calculations.h"
#include "Print.h"

using namespace std;

    int main() {
        char userContinue = 'a';//continues loop until user presses q


        // Prompt user for input and store results
        while (userContinue != 'q') {
            Banking userData;
            userData.promptUser();

            // Pass the user input on to make appropriate calculations
            Calculations calculations;
            Banking acctWithNoMonthlyDep = calculations.calculateInvestment(userData);
            Banking acctWithMonthlyDep = calculations.calculateInvestment(userData);

            // User ReportGenerator objects to relay interest info back to the user
            PrintData balanceAndInterestReport;
            balanceAndInterestReport.PrintFunc(acctWithNoMonthlyDep, acctWithMonthlyDep);

            cout << "Would you like to continue?" << endl;
            cout << "Press q to quit or any key continue: ";
            cin >> userContinue;

        }
        return 0;
    }
