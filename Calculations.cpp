#include <iostream>
#include "Banking.h"
#include "Calculations.h"
#include <vector>
#include <iomanip>
#include <string_view>

using namespace std;
//constructor
Calculations::Calculations() {}




Banking Calculations::calculateInvestment(Banking& userInput) { //Gets and sets information to be later printed in repsective parameter

    double investment = userInput.GetInvestment();
    double deposit = userInput.GetDeposit();
    double intRate = userInput.GetInterest();
    int numYears = userInput.GetTotalYears();
    vector<int> years;
    vector<vector<double>> infoDeposit;
    vector<vector<double>> infoNoDeposit;
    
    Banking SetInfoDeposit;
    for (int i = 0; i < numYears; ++i) {
        years.push_back(i + 1);
    }
    infoDeposit = BalanceWithDeposit(investment,deposit, intRate, numYears);
    infoNoDeposit = BalanceNoDeposit(investment, intRate, numYears);
    
    SetInfoDeposit.SetNumYears(years);
    SetInfoDeposit.SetEndInterest(infoDeposit.at(0));
    SetInfoDeposit.SetEndBalance(infoDeposit.at(1));
    SetInfoDeposit.SetEndInterest2(infoNoDeposit.at(0));
    SetInfoDeposit.SetEndBalance2(infoNoDeposit.at(1));

    return SetInfoDeposit;
}

vector<vector<double>> Calculations::BalanceWithDeposit(double investment, double deposit, double interest, int numOfYears) {// function to track balance with deposit
    vector<vector<double>> balanceAndInterestDeposit;
    
    vector<double> intTrackerWithDeposit;
    vector<double> balanceWithDeposit;
    

    double interestTotal = 0.0;
    double interestTally = 0.0;
    double finalInterest = 0.0;
    double realIntRate = (interest / 100.00) / 12.00;//calculates interest rate for proper multiplication
    double Balance = 0.0;
    for (int i = 0; i < (numOfYears * 12); ++i) {
        interestTally += ((interestTotal + investment) + (deposit * (i + 1))) * realIntRate;
        interestTotal = interestTally;
        if (((i + 1) % 12) == 0) {
            intTrackerWithDeposit.push_back(interestTally - finalInterest);
            finalInterest = interestTally;
            Balance = investment + (deposit * (i + 1)) + finalInterest;
            balanceWithDeposit.push_back(Balance);
            }
        }
    balanceAndInterestDeposit.push_back(intTrackerWithDeposit);
    balanceAndInterestDeposit.push_back(balanceWithDeposit);
    return balanceAndInterestDeposit; //returns  balance and accumlated interest
    }

vector<vector<double>> Calculations::BalanceNoDeposit(double investment, double interest ,int numOfYears) {// function to track balance with no deposit
    vector<vector<double>> balanceAndInterestNoDeposit;
    vector<double> intTrackerNoDeposit;
    vector<double> balanceNoDeposit;

    double interestTotal = 0.0;
    double interestTally = 0.0;
    double finalInterest = 0.0;
    double realIntRate = (interest / 100.00) / 12.00;//calculates interest rate for proper multiplication
    double Balance = 0.0;
    for (int i = 0; i < (numOfYears * 12); ++i) {
        interestTally += ((interestTotal + investment) * realIntRate);
        interestTotal = interestTally;
        if (((i + 1) % 12) == 0) {
            intTrackerNoDeposit.push_back(interestTally - finalInterest);
            finalInterest = interestTally;
            Balance = investment + finalInterest;
            balanceNoDeposit.push_back(Balance);
        }
    }
    balanceAndInterestNoDeposit.push_back(intTrackerNoDeposit);
    balanceAndInterestNoDeposit.push_back(balanceNoDeposit);
    return balanceAndInterestNoDeposit;//returns  balance and accumlated interest
}

