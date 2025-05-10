#pragma once
#include "ClsTheStaticScreen.h"
#include "ClsCurrency.h"
class ClsListCurrencies:private ClsTheStaticScreen
{

	static void PrintAllSingleCurrencyOneByOne(ClsCurrency& Currency)
	{
		cout << left << setw(30) << Currency.GetTheCountry() << "|"
			<< left << setw(25) << Currency.GetTheCurrencyCode() << "|"
			<< left <<setw(30) <<Currency.GetTheCurrencyName() << "|"
			<< left << Currency.GetTheRate() << endl;
	}
public:
	static void ShowListOfTheCurrencies()
	{
		vector<ClsCurrency>All =ClsCurrency::GetAllCurencies();
		cout << "====================================================================================-----------------------==\n";
		cout << "   country                    |       Currency Code     |         Cueerncy  Name      |    rate             |\n";
		cout << "=============================================================================================================\n";
		for (ClsCurrency& CurrentCurrencyForPrining : All)
		{
			PrintAllSingleCurrencyOneByOne(CurrentCurrencyForPrining);
		}
	}

};

