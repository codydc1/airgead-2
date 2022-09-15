#ifndef BANKING_H
#define BANKING_H
#include <string>
#include <vector>
using namespace std;

class Banking {

private: //initializes variables
	double initialInvestment;
	double monthlyDeposit;
	double interestRate;
	int totalYears;
	vector<int> numOfYears;
	vector<double> yearEndBalance;
	vector<double> yearEndInterest;

	vector<double> yearEndBalance2;
	vector<double> yearEndInterest2;

	vector<double> Input();
	vector<string> inputGuide;
public://initializes setters and getters
	Banking();
	const vector<string>& GetInputGuide() const;

	void SetTotalYears(int tYears);
	int GetTotalYears();

	void SetInvestment(double investment);
	double GetInvestment();

	void SetDeposit(double deposit);
	double GetDeposit();

	void SetInterest(double interest);
	double GetInterest();

	void SetNumYears(const vector<int>& numOfYears);
	const vector<int>& GetNumYears() const;

	void SetEndBalance(const vector<double>& yearEndBalance);
	const vector<double>& GetEndBalance() const;

	void SetEndBalance2(const vector<double>& yearEndBalance2);
	const vector<double>& GetEndBalance2() const;

	void SetEndInterest(const vector<double>& yearEndInterest);
	const vector<double>& GetEndInterest() const;

	void SetEndInterest2(const vector<double>& yearEndInterest2);
	const vector<double>& GetEndInterest2() const;

	void promptUser();
};

#endif BANKING_H
