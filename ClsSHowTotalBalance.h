#pragma once
#include "ClsTheStaticScreen.h"
#include "ClsBankClient.h"
#include "IsInputValid.h"
#include "ClsUtil.h"
class ClsSHowTotalBalance:private ClsTheStaticScreen
{
	static void _PrintingTotalBalance(ClsBankClient& Client)
	{
		cout << "\t\t\t\t " << Client.FullName() << "|\t\t\t\t " << Client.AccountBalance1 << "\t\t\t\t    |" << Client.getAccountNumber() << endl;;
	};
private :

public:
	static void ShowTotalBalance()
	{
		ClsSHowTotalBalance::PrintMinuScreen("Show Total Balance\n");
		vector<ClsBankClient>AllClients = ClsBankClient::_LoadAllClientFromFil();
		cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t\t\t\t   full Name     |    Account Balance     |    Account number\n";
	    cout << "\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

		for (ClsBankClient& Single : AllClients)
		{
			_PrintingTotalBalance(Single);
		}

	}
};

