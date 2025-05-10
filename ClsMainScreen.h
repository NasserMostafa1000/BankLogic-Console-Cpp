#pragma once
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include "ClsBankClient.h"
#include "ClsListClientScreen.h"
#include "ClsAddNewClient.h"
#include <string>
#include "ClsDeleteClient.h"
#include "UpdateClient.h"
#include "ClsDeposit.h"
#include "ClsTransactions.h"
#include"ClsUserMenu.h"
#include "Global.h"
#include "ClsShowRegisterHistory.h"
#include "ClsCurrencyMainScreen.h"
class ClsMainScreen :protected ClsTheStaticScreen
{
private:
	static void printClient(ClsBankClient& Client)
	{
		cout << "          client card\n";
		cout << "_______________________________________________________\n";
		cout << "   first name  : " << Client.FirstName() << endl;
		cout << "   second name : " << Client.SecondName() << endl;
		cout << "   Full name   : " << Client.FullName() << endl;
		cout << "   Email       : " << Client.Email() << endl;
		cout << "   Phone       : " << Client.phone() << endl;
		cout << "   acc Number  : " << Client.getAccountNumber() << endl;
		cout << "   acc Balance : " << Client.AccountBalance1 << endl;
		cout << "   password    : " << Client.PinCode << endl;
	}
	enum UserChoices
	{
		ShowAllClient = 1, AddClient = 2, Delete = 3, Update = 4, FindClient = 5, Transaction = 6, UsersMange = 7, showRegustershistory = 8,logOut=9,EnCurrency=10
	};
	static UserChoices GetUserChoice()
	{
		short userChoice = IsInputValid::ReadNumberBetween1<short>("number should be less than 8 and above 1\n", 1, 10);
		return (UserChoices)userChoice;
	}
	void ShowALlClients()
	{
		ClsListClientScreen::ShowClientsList();
	}
	enum _Permission
	{
		all=-1,showAllClients=1,addNewClient=2,DeleteClient=4,updateClient=8,findClient=16,transaction=32,
		userMenu=64,showRegusters=128
	};
	static bool IsThisMenuOnCurrentUserPermission(_Permission NumberOfPermissionMenu)
	{
		if (CurrentUser.Permission == _Permission::all)
		{
			return true;
		}
		if ((NumberOfPermissionMenu & CurrentUser.Permission) == NumberOfPermissionMenu)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	static void AddNewClients()
	{
		ClsAddNewClient::AddNewClient();
	}
	static void DeleteClients()
	{
		ClsDeleteClient::DeleteClient();
	}
	static void UpdateClients()
	{
		UpdateClient::updateClient();
	}
	static void FindClientByAccNumber()
	{
		string acccoutNumber = IsInputValid::ReadString("please enter the account number\n");
		if (!ClsBankClient::IsThisClientAlreadyExists(acccoutNumber))
		{
			cout << "             ______________________________________________________________\n";
			cout << setw(20) << "account number not found on the list\n";
			cout << "             ________________________________________________________________\n";

		}
		else
		{
			ClsBankClient Client = ClsBankClient::Find(acccoutNumber);
			printClient(Client);
		}
	}
	static void Transactions()
	{
		ClsTransactions::ShowTransActionsMenu();

	}
	static void MangeUser()
	{
		ClsUserMenu::PrintingMenuScreen();
	}
	static void Out()
	{
		{
			CurrentUser = ClsUser::Find("");	
		}
	}
	static void showRegisterHistory()
	{
		ClsShowRegisterHistory::ShowRegistrationHistory();
	}
	static void SwitchOnUserChoice()
	{
		UserChoices UserChoice = GetUserChoice();
		switch (UserChoice)
		{

		case ClsMainScreen::ShowAllClient:
		{
			if (IsThisMenuOnCurrentUserPermission(_Permission::showAllClients))
			{
				system("cls");
				ClsListClientScreen::ShowClientsList();
				system("pause>0");
				ShowMainMenu();
			}

			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}
		}
		break;

		case ClsMainScreen::AddClient: {
			if (IsThisMenuOnCurrentUserPermission(_Permission::addNewClient))
			{
				system("cls");
				AddNewClients();
				system("pause>0");
				ShowMainMenu();
			}
			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}
		}
									 break;
		case ClsMainScreen::Delete:
		{
			if (IsThisMenuOnCurrentUserPermission(_Permission::DeleteClient))
			{
				system("cls");
				DeleteClients();
				system("pause>0");
				ShowMainMenu();
				;
			}
			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}
		}
		break;
		case ClsMainScreen::Update:
		{
			if (IsThisMenuOnCurrentUserPermission(_Permission::DeleteClient))
			{
				system("cls");
				UpdateClients();
				system("pause>0");
				ShowMainMenu();
			}
			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}
		}
		break;
		case ClsMainScreen::FindClient:
		{
			if (IsThisMenuOnCurrentUserPermission(_Permission::findClient))
			{
				system("cls");
				FindClientByAccNumber();
				system("pause>0");
				ShowMainMenu();
			}
			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}
		}
		break;
		case ClsMainScreen::Transaction:
		{
			if (IsThisMenuOnCurrentUserPermission(_Permission::findClient))
			{
				system("cls");
				Transactions();
				system("pause>0");
				ShowMainMenu();
			}
			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}
		}
		break;
		case ClsMainScreen::UsersMange:
		{
			if (IsThisMenuOnCurrentUserPermission(_Permission::userMenu))
			{
				system("cls");
				MangeUser();
				ShowMainMenu();
			}
			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}

		}
		break;
		case ClsMainScreen::showRegustershistory:
			if (IsThisMenuOnCurrentUserPermission(_Permission::showRegusters))
			{
				system("cls");
				showRegisterHistory();
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}
			else
			{
				system("cls");
				cout << "access denied\n";
				system("pause>0");
				system("cls");
				ShowMainMenu();
			}

		
		case ClsMainScreen::logOut:
		{
			system("cls");
			Out();
		}
		break;
		case ClsMainScreen::EnCurrency:
		{
			system("cls");
			ClsCurrencyMainScreen::ShowCurrencyMainScreen();
			system("pause>0");
			system("cls");
			ShowMainMenu();

		}
		/*default:
			break;
		}*/

		}
	}

public:
	static 
		void ShowMainMenu()
	{
		ClsTheStaticScreen::PrintMinuScreen("Main Menu");
		cout << setw(37) << left << "                                       _____________________________\n";
		cout << setw(37) << left << "                                              Nmb Bank\n";
		cout << setw(37) << left << "                                       ______________________________\n";
		cout << setw(37) << left << "                                       [1]Show Client List          :\n";
		cout << setw(37) << left << "                                       [2]Add New Client            :\n";
		cout << setw(37) << left << "                                       [3]Delete Client             :\n";
		cout << setw(37) << left << "                                       [4]Update Client Info        :\n";
		cout << setw(37) << left << "                                       [5]Find Client               :\n";
		cout << setw(37) << left << "                                       [6]Transactions              :\n";
		cout << setw(37) << left << "                                       [7]Manage Users              :\n";
		cout << setw(37) << left << "                                       [8]Show Registers history    :\n";
		cout << setw(37) << left << "                                       [9]Log Out                   :\n";
		cout << setw(37) << left << "                                       [10]Currency Exchang          :\n";
		cout << setw(37) << left << "                                       ______________________________\n";
		SwitchOnUserChoice();

	}
};
