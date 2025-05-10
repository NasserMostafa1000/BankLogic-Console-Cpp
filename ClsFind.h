#pragma once
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include "ClsUser.h"
class ClsFind:private ClsTheStaticScreen
{
	static void _PrintingUserCard(ClsUser USerTOPrint)
	{
		cout << USerTOPrint.FullName() << endl;
		cout << USerTOPrint.Email() << endl;
		cout << USerTOPrint.phone() << endl;
		cout << USerTOPrint.Password << endl;
		cout << USerTOPrint.UserName << endl;

	}
public:
	static void FindUserByAccountNumber()
	{
		string UserName = IsInputValid::ReadString("please enter the User Name");
		while (!ClsUser::IsUserNameAlreadyExists(UserName))
		{
			 UserName = IsInputValid::ReadString("this account number is not found,please enter right account number");
		}
		ClsUser UserToGet = ClsUser::Find(UserName);
		_PrintingUserCard(UserToGet);

	}
};

