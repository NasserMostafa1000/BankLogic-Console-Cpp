#pragma once
#include "ClsBankClient.h"
#include <string>
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include "ClsDeposit.h"
#include "ClsWithdraw.h"
#include "ClsMainScreen.h"
#include "ClsSHowTotalBalance.h"
#include "ClsTransfer.h"
#include "ClsListTranserScreen.h"

using namespace std;
class ClsTransactions: private ClsTheStaticScreen
{
	enum TransactionsMenu
	{
		deposit=1,withdraw=2,checkBalance=3,menu=4,transfer=5,showTransferHistory
	};

	static void _Transfer()
	{
		ClsTransfer::transfer();
	}

	static void SwitchOnTransActionMenu(short UserChoice)
	{
		TransactionsMenu UserTransactions = TransactionsMenu(UserChoice);
		switch (UserTransactions)
		{
		case ClsTransactions::deposit: {
			system("cls");
			ClsDeposit::Deposit();
			system("pause>0");
		}
			break;
		case ClsTransactions::withdraw: {
			system("cls");
			ClsWithdraw::Withdraw();
			system("pause>0");
		}
			break;
		case ClsTransactions::checkBalance: {
			system("cls");
			ClsSHowTotalBalance::ShowTotalBalance();
			system("pause>0");
		}
				break;
		case ClsTransactions::menu:
		{
			system("cls");
		}
		case ClsTransactions::transfer:
		{
			system("cls");
			_Transfer();
			system("pause>0");

		}
		case ClsTransactions::showTransferHistory:
		{
			system("cls");
			ClsListTranserScreen::ShowListTransfer();
			system("pause>0");
		}
			break;
		default:
			break;
		}

	}
public:
	static void ShowTransActionsMenu()
	{
		ClsTheStaticScreen::PrintMinuScreen("Transactions menu");
		cout << "                         ________________________________________________\n";
		cout << "                         1-deposit                    :\n";
		cout << "                         2-withdraw                   :\n";
		cout << "                         3-Check Balance              :\n";
		cout << "                         4-Main Screen                :\n";
		cout << "                         5-transfer                   :\n";
		cout << "                         6-Show transfer history      :\n";
		cout << "                         ________________________________________________\n";
		short ChoiceNumber = IsInputValid::ReadNumberBetween1<short>("\t\t\t\tnumber should be from 1 to 5 :" ,1,6);
		ClsTransactions::SwitchOnTransActionMenu(ChoiceNumber);
    }
};

