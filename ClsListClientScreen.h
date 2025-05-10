#pragma once
#include "ClsTheStaticScreen.h"
#include "ClsBankClient.h"
#include <iomanip>
#include <iostream>
class ClsListClientScreen:protected ClsTheStaticScreen
{

private:
  static  void printClientInfo(ClsBankClient& ClientToPrint)
    {
        cout << setw(14) << ClientToPrint.getAccountNumber() << "|"
            << setw(20) << ClientToPrint.FullName() << "|" <<
            setw(10) << ClientToPrint.phone() << "|" <<
            setw(26) << ClientToPrint.Email() << "|" <<
            setw(25) << ClientToPrint.PinCode << "|" <<
            setw(20) << ClientToPrint.AccountBalance1<<"\n";
    }
	public:
        static void ShowClientsList()

        {
            system("cls");
            ClsTheStaticScreen::PrintMinuScreen("Show Clients List");
            vector<ClsBankClient>AllClients = ClsBankClient::_LoadAllClientFromFil();
            //printing headre __________
            cout << "________________________________________________________________________________________________________________\n";
            cout << "________________________________________________________________________________________________________________\n";
            cout << left << setw(14) << "Account number";
            cout << "|" << left << setw(20) << "Client Name ";
            cout << "|" << left << setw(10) << "phone ";
            cout << "|" << left << setw(26) << "email";
            cout << "|" << left << setw(25) << "pin code";
            cout  <<"|" << left << setw(20) << "balance";
            cout << "\n_____________________________________________________________________________________________________________\n";
            cout << "_______________________________________________________________________________________________________________\n";
            if (AllClients.size() == 0)
            {
                cout << "________________________________________________________________________\n";
                cout << "        no    Clients     found       on      the      system\n";
                cout << "________________________________________________________________________\n";
            }
            else
            {
                for (ClsBankClient SingleClient : AllClients)
                {
                    printClientInfo(SingleClient);
                }
            }
            cout << "press any key to get Main Menu\n";
        }

	
};

