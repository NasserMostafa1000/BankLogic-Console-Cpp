#pragma once
#include "ClsTheStaticScreen.h"
#include "ClsUser.h"
#include "IsInputValid.h"
class ClsDeleteUser :private ClsTheStaticScreen
{

public:
	static void DeleteUser()
	{
		ClsTheStaticScreen::PrintMinuScreen("Delete User  Screen");
		string USerName = IsInputValid::ReadString("please enter your User Name");
		while (!ClsUser::IsUserNameAlreadyExists(USerName))
		{
			 USerName = IsInputValid::ReadString("please enter User Name,this user name is not already exists ");
		}
		ClsUser UserToDelete = ClsUser::Find(USerName);

		if (UserToDelete.Delete())
		{
			cout << "deletion success\n";
		}
		else
		{
			cout << "deletion failed\n";
		}
	}


};