#pragma once
#include <string>
#include <vector>
#include "ClsString.h"
#include <fstream>
#include <iostream>
using namespace std;
class ClsCurrency
{

private:
	enum EnMode{emptyMode=1,UpdateMode=2};
	EnMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	vector<ClsCurrency>_GetAllCurencies()
	{
		vector<ClsCurrency>ALL;
		fstream file;
		file.open("Currencies.txt", ios::in);
		if (file.is_open())
		{
			string Line;
			while (getline(file, Line))
			{
				ALL.push_back(_ConvertDataTOCurrencyClass(Line));
			}
			file.close();
		}
		return ALL;
	}
static 	ClsCurrency _ConvertDataTOCurrencyClass(string LineFromFile)
	{
		///
		vector<string>TheCurrentClass = ClsString::split(LineFromFile, "#//#");
		return ClsCurrency(EnMode::UpdateMode, TheCurrentClass.at(0), TheCurrentClass.at(1), TheCurrentClass.at(2)
			, stof(TheCurrentClass.at(3)));
	}
string _ReturnCurrencyTOLine(ClsCurrency &Currency)
{
	string line = "";
	line += Currency.GetTheCountry() + "#//#";
	line += Currency.GetTheCurrencyCode() + "#//#";
	line += Currency.GetTheCurrencyName() + "#//#";
	line += to_string(Currency.GetTheRate());
	return line;
}
void _SaveVectorTOFile(vector<ClsCurrency>&ALL)
{
	fstream file;
	file.open("currencies.txt", ios::out);
	if(file.is_open())
	{
		for (ClsCurrency& CurrentCurrency : ALL)
		{
			file << _ReturnCurrencyTOLine(CurrentCurrency) << endl;;
		}
	}
	file.close();

}
void _Update()
{
	vector<ClsCurrency>ALL=_GetAllCurencies();
	for (ClsCurrency &CurrentCurrency : ALL)
	{
		if (CurrentCurrency._CurrencyCode == _CurrencyCode)
		{
			CurrentCurrency = *this;
		}
	}
	_SaveVectorTOFile(ALL);
}
static ClsCurrency _GetEmptyObject()
{
	return ClsCurrency(EnMode::emptyMode, "", "", "", 0);
}

public:
	ClsCurrency(EnMode Mode, string Country, string currencyCode, string currencyName, float Rate)
	{
		_Mode = Mode; _Country = Country;
		_CurrencyCode = currencyCode; _CurrencyName = currencyName;
		_Rate = Rate;
	}
	static vector<ClsCurrency>GetAllCurencies()
	{
		vector<ClsCurrency>ALL;
		fstream file;
		file.open("Currencies.txt", ios::in);
		if (file.is_open())
		{
			string Line;
			while (getline(file, Line))
			{
			ALL.push_back(_ConvertDataTOCurrencyClass(Line));
			}
			file.close();
		}
		return ALL;
	}
	//declare property set
	void UpdateRate(float rate)
	{
		_Rate = rate;
		_Update();
	}
//	property get
	string GetTheCountry()
	{
		return _Country;
	}
	string GetTheCurrencyName()
	{
		return _CurrencyName;
	}
	string GetTheCurrencyCode()
	{
		return _CurrencyCode;
	}
	static ClsCurrency GetEmptyObject()
	{
		return ClsCurrency(EnMode::emptyMode, "", "", "", 0);
	}
	 bool IsEmpty()
	{
		 return _Mode==EnMode::emptyMode;
	}
	float GetTheRate()
	{
		return _Rate;
	}
	static ClsCurrency FindByCode(string CurrencyCode)
	{
		string CurrenyAfterUppring=ClsString::upperAllString(CurrencyCode);
		vector<ClsCurrency>AllCurencies = GetAllCurencies();
		for (ClsCurrency& CurrentCurrency : AllCurencies)
		{
			if (CurrentCurrency.GetTheCurrencyCode() == CurrenyAfterUppring)
			{
				return CurrentCurrency;
			}
		}
		return GetEmptyObject();

	}
	static ClsCurrency FindByCountry(string Country)
	{
		string CurrenyAfterUppring = ClsString::upperAllString(Country);

		vector<ClsCurrency>AllCurencies = GetAllCurencies();
		for (ClsCurrency &CurrentCurrency : AllCurencies)
		{
			if (CurrentCurrency.GetTheCountry() == CurrenyAfterUppring)
			{
				return CurrentCurrency;
			}
		}
		return GetEmptyObject();
	}
	static bool IsCurrencyIsAlreadyExistsByCode(string CurrencyCode)
	{
		ClsCurrency Currency=FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	static bool IsCurrencyIsAlreadyExistsByCountry(string CurrencyCOuntry)
	{
		ClsCurrency Currency = FindByCountry(CurrencyCOuntry);
		return (!Currency.IsEmpty());
	}
};

