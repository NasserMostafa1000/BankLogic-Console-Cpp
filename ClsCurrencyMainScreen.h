#pragma once
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include <iomanip>
#include "ClsListCurrencies.h"
#include "ClsFindCurrency.h"
#include "CLsUpdateRate.h"
#include "ClsCurrencyCalculator.h"
class ClsCurrencyMainScreen :private ClsTheStaticScreen
{


	enum _CurrencyMenuList
	{
		EnLisCurrency = 1, EnFindCurrency = 2, EnUpdateRate = 3, EnCurrencyCalculaotr = 4, EnMainMenu = 5
	};
	static void PerformToUserChoice(short Number)
	{
		_CurrencyMenuList EnUserNumber = _CurrencyMenuList(Number);
		switch (EnUserNumber)
		{
		case ClsCurrencyMainScreen::EnLisCurrency:
		{
			system("cls");
			ClsListCurrencies::ShowListOfTheCurrencies();
			system("pause>0");
		}
		break;
		case ClsCurrencyMainScreen::EnFindCurrency:
		{
			system("cls");
			ClsFindCurrency::FindCurrency();
			system("pause>0");
		}
		break;
		case ClsCurrencyMainScreen::EnUpdateRate:
		{
			system("cls");
			CLsUpdateRate::UpdateRate();
			system("pause>0");

		}
		break;
		case ClsCurrencyMainScreen::EnCurrencyCalculaotr:
		{
			system("cls");
			ClsCurrencyCalculator::ShowCurrencyCalculator();
			system("pause>0");

		}
			break;
		case ClsCurrencyMainScreen::EnMainMenu:
			break;
		default:
			break;
		}
	}



public:
	static void ShowCurrencyMainScreen()
	{
		ClsTheStaticScreen::PrintMinuScreen("CurrencyMenu");
		cout << setw(37) << left << "========================================================\n";
		cout << setw(37) << left << "          1-List Currencies         .\n";
		cout << setw(37) << left << "          2-Find Currency           .\n";
		cout << setw(37) << left << "          3-Update Rate             .\n";
		cout << setw(37) << left << "          4-Currency Calculator     .\n";
		cout << setw(37) << left << "          5-Main Menu               .\n";
		cout << setw(37) << left << "========================================================\n";
		short Number = IsInputValid::ReadNumberBetween1<short>("please enter number between 1 to 5\n", 1, 5);
		PerformToUserChoice(Number);
	}

};

