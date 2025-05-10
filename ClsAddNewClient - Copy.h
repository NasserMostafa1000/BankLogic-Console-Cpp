#pragma once
#include "ClsBankClient.h"
#include "ClsBankClient.h"
#include "ClsTheStaticScreen.h"

class ClsAddNewClient
{
private:
   static void ReadClientInfo(ClsBankClient& Client)
    {
        Client.SetFirstName(IsInputValid::ReadString("please enter first name\n"));

        Client.SetSecondName(IsInputValid::ReadString("please enter second name\n"));

        Client.SetEmail(IsInputValid::ReadString("please enter yourthe new email\n"));

        Client.SetPhone(IsInputValid::ReadString("please enter the new phone \n"));

        Client.PinCode = IsInputValid::ReadString("please enter the new pin code\n");
        Client.SetId(IsInputValid::ReadString("please enter the new Id\n"));

        Client.AccountBalance1 = IsInputValid::ReadFloatNumber("please enter new acc balance\n");
    }

public:
    static void AddNewClient()
    {
        ClsTheStaticScreen::PrintMinuScreen("Add New Client Screen\n");
        cout << "AddNewClient\n___________________\n";
        string AccountNumber = IsInputValid::ReadString("please enter the account number \n");

        while (ClsBankClient::IsThisClientAlreadyExists(AccountNumber))
        {
            cout << "account number is already exists try with other one\n";
            string AccountNumber = IsInputValid::ReadString("please enter a new account number \n");
        }
        ClsBankClient Client = ClsBankClient::GetAddNewMode(AccountNumber);
        ReadClientInfo(Client);
        ClsBankClient::EnSaveResult SavingResult;

        SavingResult = Client.Save();
        switch (SavingResult)
        {
        case ClsBankClient::EnSavingSuccess: {
            cout << "saving complete successfully \n";
        }
                                           break;
        case ClsBankClient::EnSavingFailEmptyObject:
        {
            cout << " error empty object \n";

        }
        break;
        case ClsBankClient::EnSavingFailAccountNumberExists:
            cout << " error Account Number Is exists \n";
            break;
        default:
            break;
        }
    }

};

