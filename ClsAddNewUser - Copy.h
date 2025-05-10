#pragma once
#include <string>
#include "IsInputValid.h"
#include "ClsUser.h"
#include "ClsTheStaticScreen.h"
#include "ClsUtil.h"


class ClsAddNewUser :private ClsTheStaticScreen
{
	static void _ReadTheNewUserPermission(ClsUser& TheNewUser)
	{
		char OwnerChoice = IsInputValid::ReadChar("If you want to give him access on the Client List\n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 1;
		}
		 OwnerChoice = IsInputValid::ReadChar("If you want to give him access on the Add New Client\n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 2;
		}
		 OwnerChoice = IsInputValid::ReadChar("If you want to give him access to delete client \n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 4;
		}
		 OwnerChoice = IsInputValid::ReadChar("If you want to give him access on update client\n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 8;
		}
		 OwnerChoice = IsInputValid::ReadChar("If you want to give him access to find clients\n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 16;
		}
		 OwnerChoice = IsInputValid::ReadChar("If you want to give him access on transactions menu\n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 32;
		}
		 OwnerChoice = IsInputValid::ReadChar("If you want to give him access on manage users\n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 64;
		}
		OwnerChoice = IsInputValid::ReadChar("If you want to give him access on Time & Date Registration \n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 128;
		}
	}
	static void _ReadNewUserInformation(ClsUser& TheNewUser)
	{
		TheNewUser.SetFirstName(IsInputValid::ReadString("please enter first name\n"));
		TheNewUser.SetSecondName(IsInputValid::ReadString("please enter second name\n"));
		TheNewUser.SetUserName(IsInputValid::ReadString("please enter username\n"));
		TheNewUser.SetPassword(IsInputValid::ReadString("please enter password\n "));
		TheNewUser.SetEmail(IsInputValid::ReadString("please enter Email\n"));
		TheNewUser.SetPhone(IsInputValid::ReadString("please enter Phone\n"));
		char CheckIfWillBeAccessAtAllPermissions = 'y';
		char UserAccess = IsInputValid::ReadChar("do you want to give this user all permission  if yes choose y or Y\n");
		if (CheckIfWillBeAccessAtAllPermissions == UserAccess)
		{
			TheNewUser.SetPermission(-1);
		}
		else
		{
			_ReadTheNewUserPermission(TheNewUser);
		}

	}
	
public:
	static void _AddNewUser()
	{
		ClsTheStaticScreen::PrintMinuScreen("Add New menu");
		ClsUser TheNewUser = ClsUser::GetAddNewUserObject();
		_ReadNewUserInformation(TheNewUser);
		ClsUser::EnSaveResult ResultOFSaving = TheNewUser.Save();
		switch (ResultOFSaving)
		{
		case ClsUser::EnSavingSuccess:
		{
			cout << "adding success\n";
		}
			break;
		case ClsUser::EnSavingFailEmptyObject:
		{
			cout << "EnSavingFailEmptyObject\n";
		}
			break;
		case ClsUser::EnSavingFailUserNameIsAlreadyExists:
		{
			cout << "EnSavingFailUserNameIsAlreadyExists\n";
		}
			break;
		default:
			break;
		}

   }
};

