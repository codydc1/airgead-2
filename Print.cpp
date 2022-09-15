#include <string_view>
#include <iostream>
#include <iomanip>
#include "Print.h"
#include "Calculations.h"

using namespace std;

//Constructor
PrintData::PrintData() {}

void PrintData::PrintFunc(Banking& dataWDeposit, Banking& dataNoDeposit){  //Creates instance of balance with and without deposit
    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    PrintNoDeposit(dataNoDeposit);

    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    PrintDeposit(dataWDeposit);
}

void PrintData::PrintDeposit(Banking& data){
//variables to be printed
    vector<int> years = data.GetNumYears();
    vector<double> yearEndBalancesDeposit = data.GetEndBalance();
    vector<double> yearEndEarnedInterestsDeposit = data.GetEndInterest();


    // takes info and displays
    for (int i = 0; i < years.size(); ++i) {
        cout << setw(9) << years.at(i) << fixed << setprecision(2);
        cout << setw(26) << yearEndBalancesDeposit.at(i) << fixed << setprecision(2);
        cout << setw(27) << yearEndEarnedInterestsDeposit.at(i) << fixed << setprecision(2) << endl;
    }
    cout << endl << endl;
}

    void PrintData::PrintNoDeposit(Banking& data){
        // variables to be printed
        vector<int> years = data.GetNumYears();
        vector<double> yearEndBalancesDeposit2 = data.GetEndBalance2();
        vector<double> yearEndEarnedInterestsDeposit2 = data.GetEndInterest2();


        // takes info and displays
        for (int i = 0; i < years.size(); ++i) {
            cout << setw(9) << years.at(i) << fixed << setprecision(2);
            cout << setw(26) << yearEndBalancesDeposit2.at(i) << fixed << setprecision(2);
            cout << setw(27) << yearEndEarnedInterestsDeposit2.at(i) << fixed << setprecision(2) << endl;
        }
        cout << endl << endl;
    }

