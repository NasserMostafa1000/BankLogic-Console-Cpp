#pragma once
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include "ClsCurrency.h"
class CLsUpdateRate:private ClsTheStaticScreen
{


public:
	static void UpdateRate()
	{
		ClsTheStaticScreen::PrintMinuScreen("Update rate screen\n");
	string NameOfTHeCurrency=	IsInputValid::ReadString("please enter the name of the currency that you would exchange\n");
	while (!ClsCurrency::IsCurrencyIsAlreadyExistsByCode(NameOfTHeCurrency))
	{
	 NameOfTHeCurrency = IsInputValid::ReadString("please enter the name of the currency that you would exchange\n");

	}
	ClsCurrency CurrencyToUpdate = ClsCurrency::FindByCode(NameOfTHeCurrency);
	float theNewRate= IsInputValid::ReadFloatNumber("please enter the new rate");
	CurrencyToUpdate.UpdateRate(theNewRate);
	cout << "updating succesfully\n";

	}

};

