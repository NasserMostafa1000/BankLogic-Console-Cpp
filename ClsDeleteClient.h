#pragma once
#include "ClsBankClient.h"
#include "ClsTheStaticScreen.h"
class ClsDeleteClient :protected ClsTheStaticScreen
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


public:

    static  void DeleteClient()
    {
        ClsTheStaticScreen::PrintMinuScreen("Delete Client Screen \n");
        cout << "Delete Client\n___________________\n";
        string AccountNumber = IsInputValid::ReadString("please enter the account number \n");

        while (!ClsBankClient::IsThisClientAlreadyExists(AccountNumber))
        {
            cout << "account number is not found\n";
            string AccountNumber = IsInputValid::ReadString("please enter the account number \n");
        }
        ClsBankClient DeletedClient = ClsBankClient::Find(AccountNumber);
        printClient(DeletedClient);
        char SureForDelete = 'y';
        cout << "are you sure for delete This Client?if you sure from that click on Y or y\n";
        char OwnerChoice;
        cin >> OwnerChoice;
        if (OwnerChoice == SureForDelete)
        {
            if (DeletedClient.DeleteClient())
            {
                cout << "deletion success\n";
                printClient(DeletedClient);

            }
            else
            {
                cout << "deletion failed\n";
            }
        }
    }

	
};

