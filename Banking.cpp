#include "Banking.h"
#include <iostream>
using namespace std;

Banking::Banking()
{
    Banking::inputGuide = { //Creates prompts for user input
        "Initial Investment Amount: $", "Monthly Deposit: $", "Annual Interest: % ", "Number of years: "
    };
};
//Setters and getters
const vector<string>& Banking::GetInputGuide() const {
    return inputGuide;
}
void Banking::SetTotalYears(int tYears) {
    totalYears = tYears;
}
int Banking::GetTotalYears() {
    return totalYears;
}
void Banking::SetInvestment(double investment) {
    initialInvestment = investment;
}
double Banking::GetInvestment() {
    return initialInvestment;
}
void Banking::SetDeposit(double deposit) {
    monthlyDeposit = deposit;
}
double Banking::GetDeposit() {
    return monthlyDeposit;
}
void Banking::SetInterest(double interest) {
    interestRate = interest;
}
double Banking::GetInterest() {
    return interestRate;
}

void Banking::SetNumYears(const vector<int>& years) {
    numOfYears = years;
}
const vector<int>& Banking::GetNumYears() const {
    return numOfYears;
}
void Banking::SetEndBalance(const vector<double>& endBalance) {
    yearEndBalance = endBalance;
}
const vector<double>& Banking::GetEndBalance() const {
    return yearEndBalance;
}
void Banking::SetEndInterest(const vector<double>& endInterest) {
    yearEndInterest = endInterest;
}
const vector<double>& Banking::GetEndInterest() const {
    return yearEndInterest;
}
//sets and returns values for interest and balance without deposit
void Banking::SetEndInterest2(const vector<double>& endInterest2) {
    yearEndInterest2 = endInterest2;
}
const vector<double>& Banking::GetEndInterest2() const {
    return yearEndInterest2;
}

    void Banking::SetEndBalance2(const vector<double>&endBalance2) {
        yearEndBalance2 = endBalance2;
    }
    const vector<double>& Banking::GetEndBalance2() const {
        return yearEndBalance2;
    }




void Banking::promptUser() { //takes input and sets into main parameters
    vector<double> depositDetails;
    char quitCmd = 'a';
    while (quitCmd != 'q') {
        depositDetails.clear();
        depositDetails = Input();
        if (depositDetails.size() == 4) {
            SetInvestment(depositDetails.at(0));
            SetDeposit(depositDetails.at(1));
            SetInterest(depositDetails.at(2));
            SetTotalYears(depositDetails.at(3));

            quitCmd = 'q';
        }
    }
}
vector<double> Banking::Input() { //takes user input and validates
    vector<double> responses;


    for (int i = 0; i < inputGuide.size(); ++i) {
        double userInput;
        string prompt = inputGuide.at(i);
        cout << prompt;
        cin >> userInput;
        if (userInput > 0) {
            responses.push_back(userInput);
        }
        else if (isdigit(userInput) == false){
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            break;
        }
    }
    return responses;
}
