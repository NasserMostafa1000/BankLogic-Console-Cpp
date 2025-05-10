#pragma once
#include <string>
#include<iostream>
#include "ClsBankClient.h"
#include "ClsTheStaticScreen.h"
#include <iostream>
using namespace std;
class ClsDeposit:ClsTheStaticScreen
{



public:
	static  void Deposit()
	{
		ClsTheStaticScreen::PrintMinuScreen("Deposit Menu");
		string AccountNumber = IsInputValid::ReadString("please enter your account Number");
		while (!ClsBankClient::IsThisClientAlreadyExists(AccountNumber))
		{
			cout << "Client with " << AccountNumber << "Is not found On The List\n";
		}
	ClsBankClient ClientForDeposit=ClsBankClient::Find(AccountNumber);
	double AmountForDeposit = 0;
	cout << "please enter the deposit amount \n";
	cin >> AmountForDeposit;
	ClientForDeposit.Deposit(AmountForDeposit);
	cout << "Amount deposit successfully\n";
	}

};

