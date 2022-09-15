#ifndef Print
#define Print


#include <vector>
#include "Banking.h"
#include "Calculations.h"

using namespace std;


class PrintData
{
public:
	PrintData();//constructor
	void PrintFunc(Banking& dataWDeposit, Banking& dataNoDeposit);//takes data for calculations with and without deposit to be printed

private:
	void PrintDeposit(Banking& data);//stores printing information for info with deposit
	void PrintNoDeposit(Banking& data); //store information for info without deposit
};

#endif //Print
