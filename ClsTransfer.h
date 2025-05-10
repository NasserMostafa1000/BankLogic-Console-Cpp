#pragma once
#include <string>
#include "Global.h"
#include "ClsBankClient.h"
#include "IsInputValid.h"
#include "clsDate.h"
#include <fstream>
class ClsTransfer
{
    static string _ReturnTransferInfoToLine(string accountFrom, string AccountTo, double amount, double accountFromBalance, double accountToBalance)
    {
        Date date = GetSystemDate();
        string Line = "";
        Line += to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year) + "-";
        Time  date2 = ClsDate::getCurrentTime();
        Line += to_string(date2.hours) + ":" + to_string(date2.minutes) + ":" + to_string(date2.seconds) + "##";
        Line += accountFrom + "##";
        Line += AccountTo + "##";
        Line += to_string(amount) + "##";
        Line += to_string(accountFromBalance - amount) + "##";
        Line += to_string(accountToBalance + amount)+"##";
        Line += CurrentUser.UserName;
        return Line;
    }

    static void SaveTransferInfoTOFile(ClsBankClient &AccountWillSend, ClsBankClient &AccountWillReceive,double amount)
    {
        fstream file;
        file.open("TransferInfo.txt", ios::app);
        if (file.is_open())
        {
            file << _ReturnTransferInfoToLine(AccountWillSend.getAccountNumber(), AccountWillReceive.getAccountNumber(), amount, AccountWillSend.AccountBalance1, AccountWillReceive.AccountBalance1) << endl;;
        }
        file.close();
    }

public:
    static void transfer()
    {
    string AccountNumberThatWillSendMoney = IsInputValid::ReadString("please enter the account number that you will send the money from it\n");

    if (!ClsBankClient::IsThisClientAlreadyExists(AccountNumberThatWillSendMoney))
    {
        cout << "this account number is not exist on the list yet\n";
    }
    else
    {
        ClsBankClient UserToSend = ClsBankClient::Find(AccountNumberThatWillSendMoney);

        string AccountNumberThatWillReceiveMoney = IsInputValid::ReadString("please enter the account number that you will receive the money on  it\n");

        if (!ClsBankClient::IsThisClientAlreadyExists(AccountNumberThatWillReceiveMoney))
        {
            cout << "this account number is not exist on the list yet\n";
        }
        else
        {
            ClsBankClient UserToReceive = ClsBankClient::Find(AccountNumberThatWillReceiveMoney);

            double amountToTransfer = IsInputValid::ReadNumber<double>("please enter the amount that you want to send: ");

            while (amountToTransfer > UserToSend.AccountBalance1)
            {
                amountToTransfer = IsInputValid::ReadNumber<double>("please enter an amount less than your balance: ");
            }
            SaveTransferInfoTOFile(UserToSend, UserToReceive, amountToTransfer);

            // عملية الخصم والإضافة
            cout << "Operation done successfully. Your balance before the operation was " << UserToSend.AccountBalance1
                << " and after it is " << UserToSend.AccountBalance1 - amountToTransfer << endl;

            UserToSend.AccountBalance1 -= amountToTransfer;
            UserToReceive.AccountBalance1 += amountToTransfer;
            // حفظ التغييرات
            UserToSend.Save();
            UserToReceive.Save();
        }
    }
}



};

