#pragma once
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include"ClsString.h"
#include "ClsCurrency.h"
class ClsCurrencyCalculator:private ClsTheStaticScreen
{

	static ClsCurrency _ReadCurrency(string CurrencyFrom)
	{
		//if  the currency not exists go in an infint loop
		while (!ClsCurrency::IsCurrencyIsAlreadyExistsByCode(CurrencyFrom))
		{
			CurrencyFrom = IsInputValid::ReadString("please enter right currency code\n");

		}
		//if already exists
		 ClsCurrency ObCurrencyFrom = ClsCurrency::FindByCode(CurrencyFrom);
		 return ObCurrencyFrom;
	}
	static void _PrintCurrency(ClsCurrency &Currency)
	{
		cout << "================================================================\n";
		cout << "country   : " << Currency.GetTheCountry()<<endl;
		cout << "Code      : " << Currency.GetTheCurrencyCode() << endl;
		cout << "Name      : " << Currency.GetTheCurrencyName () << endl;
		cout << "Rate      : " << Currency.GetTheRate() << endl;
		cout << "================================================================\n";

	}
	static float _CalculateCurrenciesOnUsdPrice(ClsCurrency &CurrencyFrom,float Amount)
	{
		return (Amount / CurrencyFrom.GetTheRate());
	}
	static void _Calculate(ClsCurrency &CurrencyFrom,ClsCurrency &CurrecnyTo,float Amount,string StCurrencyTo)
	{
		if (ClsString::upperAllString(StCurrencyTo) == "USD")
		{
			cout << "Convert From\n";
			_PrintCurrency(CurrencyFrom);
			cout << Amount << CurrencyFrom.GetTheCurrencyCode() << "="
				<< _CalculateCurrenciesOnUsdPrice(CurrencyFrom, Amount) << CurrecnyTo.GetTheCurrencyCode() << endl;
		}
		else
		{
			float CurrencyAfterConvertingYoUSD = _CalculateCurrenciesOnUsdPrice(CurrencyFrom, Amount);
			cout << "Convert From\n";
			_PrintCurrency(CurrencyFrom);
			cout << Amount << CurrencyFrom.GetTheCurrencyCode() << "="
				<< _CalculateCurrenciesOnUsdPrice(CurrencyFrom, Amount) << CurrecnyTo.GetTheCurrencyCode() << endl;
			cout << "Convert To\n";
			_PrintCurrency(CurrecnyTo);
			cout << Amount << CurrencyFrom.GetTheCurrencyCode() << "=" << CurrencyAfterConvertingYoUSD * CurrecnyTo.GetTheRate() << CurrecnyTo.GetTheCurrencyCode();;


		}
	}
public:
	static void ShowCurrencyCalculator()
	{
		string StCurrencyFrom = IsInputValid::ReadString("please enter currency 1 code\n");
		ClsCurrency CurrencyFrom = _ReadCurrency(StCurrencyFrom);
		string StCurrencyTo = IsInputValid::ReadString("please enter currency 2 code\n");
		ClsCurrency CurrencyTo = _ReadCurrency(StCurrencyTo);
		float Amount = IsInputValid::ReadFloatNumber("enter the amount\n");
		


	}
};

