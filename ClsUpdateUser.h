#pragma once
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include "ClsUser.h"
#include "ClsUtil.h"
class ClsUpdateUser:private ClsTheStaticScreen
{
private:
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
		OwnerChoice = IsInputValid::ReadChar("If you want to give him access on time and date registration\n");
		if (OwnerChoice == 'y')
		{
			TheNewUser.Permission += 128;
		}
		 
	}

	static void _UpdateUserInfo(ClsUser &UserToUpdate)
	{
		UserToUpdate.SetFirstName(IsInputValid::ReadString("please enter the first name"));
		UserToUpdate.SetSecondName(IsInputValid::ReadString("please enter the second name"));
		UserToUpdate.SetPassword(IsInputValid::ReadString("please enter the password"));
		UserToUpdate.SetPassword(ClsUtil::encryption(UserToUpdate.Password));
		UserToUpdate.SetEmail(IsInputValid::ReadString("please enter the Email"));
		UserToUpdate.SetPhone(IsInputValid::ReadString("please enter the Phone"));
		char CheckIfWillBeAccessAtAllPermissions = 'y';
		char UserAccess = IsInputValid::ReadChar("do you want to give this user all permission  if yes choose y or Y\n");
		if (CheckIfWillBeAccessAtAllPermissions == UserAccess)
		{
			UserToUpdate.SetPermission(0);
		}
		else
		{
			_ReadTheNewUserPermission(UserToUpdate);
		}
	}

public:
	static void UpdateUser()
	{
		ClsTheStaticScreen::PrintMinuScreen("Update User Info Menu");
		string UserName = IsInputValid::ReadString("Please enter the user name that you want to delete");
		while (!ClsUser::IsUserNameAlreadyExists(UserName))
		{
			UserName = IsInputValid::ReadString("This USer Name not found on the list");
		}
		ClsUser UserTOUpdate = ClsUser::Find(UserName);
		_UpdateUserInfo(UserTOUpdate);
		ClsUser::EnSaveResult UpdatingResult=UserTOUpdate.Save();
		switch (UpdatingResult)
		{
		case ClsUser::EnSavingSuccess:
			cout << "saving success\n";
			break;
		case ClsUser::EnSavingFailEmptyObject:
			cout << "saving Fail Empty Object\n";

			break;
		case ClsUser::EnSavingFailUserNameIsAlreadyExists:
			cout << "Saving Fail UserName IsAlready Exists\n";
			break;
		default:
			break;
		}

	}

};

