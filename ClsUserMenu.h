#pragma once
#include "ClsTheStaticScreen.h"
#include "ClsShowUserList.h"
#include "ClsAddNewUser.h"
#include "ClsDeleteUser.h"
#include "ClsUpdateUser.h"
#include "ClsFind.h"
#include "ClsMainScreen.h"

class ClsUserMenu: private ClsTheStaticScreen
{
 enum _EnUserMenuChoice
	{
		ShowListOfUsers = 1, addNewUser = 2, deleteUser = 3, updateUser = 4, findUser = 5, MainMenu = 6,transfer=7
	};
static void _SHowListOfUsers()
	{
	//	cout<<"ListOfUsersWillBeHere"
	ClsShowUserList::ShowUserList();
	}
static void _AddNewUser()
	{
		//cout<<"add new user code will be here\n";
	ClsAddNewUser::_AddNewUser();
	}
static void _DeleteUser()
	{
		//cout<<"DeleteUserCodeWIllBeHere\n";
	ClsDeleteUser::DeleteUser();
	}
static void _UpdateUser()
	{
	ClsUpdateUser::UpdateUser();
	}
static void _FindUser()
	{
	ClsFind::FindUserByAccountNumber();
	}

static void _PerformToUserChoice(_EnUserMenuChoice UserChoice)
	{
		switch (UserChoice)
		{
		case ClsUserMenu::ShowListOfUsers: {
			system("cls");
			_SHowListOfUsers();
			system("pause<0");
		//	ClsMainScreen::GetMainMenu();
		}
										 break;
		case ClsUserMenu::addNewUser: {
			system("cls");
			_AddNewUser();
			system("pause<0");
		}

									break;
		case ClsUserMenu::deleteUser:
		{
			system("cls");
			_DeleteUser();
			system("pause<0");
		}
		break;
		case ClsUserMenu::updateUser:
		{
			system("cls");
			_UpdateUser();
			system("pause<0");
		}
		break;
		case ClsUserMenu::findUser:
		{
			system("cls");
			_FindUser();
			system("pause<0");
		}
			break;
		case ClsUserMenu::MainMenu:
		{
		//	system("cls");
		//	ClsMainScreen::GoBackMainMenu();
		}
			break;
		default:
			break;
		}
	}
public:
	static void PrintingMenuScreen()
	{
		ClsTheStaticScreen::PrintMinuScreen("User Menu Screen");
		cout << setw(37) << left << "" << "___________________________\n";
		cout << setw(37) << left << "" << "1-Show List Of Users :\n";
		cout << setw(37) << left << "" << "2-add new user       :\n";
		cout << setw(37) << left << "" << "3-delete user        :\n";
		cout << setw(37) << left << "" << "4-update user        :\n";
		cout << setw(37) << left << "" << "5-Find user          :\n";
		cout << setw(37) << left << "" << "6-Main menu          :\n";
		cout << setw(37) << left << "" << "___________________________\n";
		cout << setw(37) << left << "" << "please choose number from 1 to 6\n";
		short num;
		cin >>  num;
		_EnUserMenuChoice UserChoice = _EnUserMenuChoice(num);
		_PerformToUserChoice(UserChoice);

	}

};

