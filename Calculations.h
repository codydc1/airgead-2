#pragma once
#ifndef Calculations_H
#define Calculation_H

#include <vector>
#include "Banking.h"

using namespace std;
class Calculations
{
public:
	Calculations();//constructor
	Banking calculateInvestment(Banking& data);//function to store calculations
private:
	vector<vector<double>> BalanceWithDeposit(double investment, double deposit, double interest, int numOfYears); //stores calculations for balance with deposit

	vector<vector<double>> BalanceNoDeposit(double investment, double interest, int numOfYears); //stores caclulation for balance without deposit
};

#endif Calculations_H
