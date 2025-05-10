#pragma once
#include "ClsTheStaticScreen.h"
#include  "ClsBankClient.h"
#include "IsInputValid.h"
class UpdateClient:ClsTheStaticScreen
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
public:
   static void updateClient()
    {
       ClsTheStaticScreen::PrintMinuScreen("Update Client Screen\n");
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = IsInputValid::ReadString("please enter your account number\n");

        while (!ClsBankClient::IsThisClientAlreadyExists(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = IsInputValid::ReadString("in valid account number please enter the valid account number \n");
        }

        ClsBankClient Client1 = ClsBankClient::Find(AccountNumber);
        printClient(Client1);
        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";


        ReadClientInfo(Client1);

        ClsBankClient::EnSaveResult SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  ClsBankClient::EnSaveResult::EnSavingSuccess:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            printClient(Client1);
            break;
        }
        case ClsBankClient::EnSaveResult::EnSavingFailEmptyObject:
        {
            cout << "\nError  Empty object\n";
            break;

        }

        }
    }

};

