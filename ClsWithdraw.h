#pragma once
#include <string>
#include<iostream>
#include "ClsBankClient.h"
#include "ClsTheStaticScreen.h"
#include <iostream>
using namespace std;

class ClsWithdraw :private ClsTheStaticScreen
{
public:
	static void Withdraw() {
		string _AccountNumber = IsInputValid::ReadString("please enter your account Number");
		while (!ClsBankClient::IsThisClientAlreadyExists(_AccountNumber))
		{
			cout << "this account number is not found On the list\n";
		}
		ClsBankClient ClientForWithdraw = ClsBankClient::Find(_AccountNumber);
		double amount = 0;
		cout << "please enter the amount that you want to withdraw\n";
		cin >> amount;
		if (ClientForWithdraw.Withdraw(amount)) {
			cout << "successfully operation\n";
		}
		else
		{
			cout << "please enter amount  less than your balance {" << ClientForWithdraw.AccountBalance1 << "}" << endl;
		}
	}
};

