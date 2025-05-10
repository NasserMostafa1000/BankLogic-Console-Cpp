#pragma once
#include "ClsMainScreen.h"
#include "ClsTheStaticScreen.h"
#include "IsInputValid.h"
#include "ClsUser.h"
#include "Global.h"
#include <fstream>
#include "clsDate.h"
#include "ClsUtil.h"
//RegistertionTime&date
using namespace std;
class ClsLogin:protected ClsTheStaticScreen
{
	static void _SaveLineOfTimeAndDateToFile(string Line)
	{
		fstream file;
		file.open("RegistertionTime&date.txt", ios::app);
		if (file.is_open())
		{
			file << Line << endl;
		}
	}
	static void _LoginRegisterTmeAndDateToLineAndSaveItToFile()
	{
		Date RegisterDate = GetSystemDate();
		Time RegisterTime = ClsDate::getCurrentTime();
		string Line = "";
		Line += to_string(RegisterDate.Day) + "/" + to_string(RegisterDate.Month) + "/" + to_string(RegisterDate.Year) + "-" + to_string(RegisterTime.hours)+"-"
			+ to_string(RegisterTime.minutes) +"-" + to_string(RegisterTime.seconds) + "##";
		Line += CurrentUser.UserName + "##";
		//ClsUtil::Encryption(CurrentUser.Password, 120);
		Line += CurrentUser.Password + "##";
		Line += to_string(CurrentUser.Permission);
		_SaveLineOfTimeAndDateToFile(Line);
	
	}
public:
	static bool Login()
	{
		short counter=3;
		ClsTheStaticScreen::PrintMinuScreen("Login Screen");
		string	UserName;
		string	Password;
		UserName = IsInputValid::ReadString("please enter  UserName");
		Password = IsInputValid::ReadString("please enter  password");
		counter--;
		ClsUser User = ClsUser::Find(UserName, Password);
		while (User.IsEmpty() && counter>0)
		{
			cout << "invalid data you have {" << counter << "} time/s and you will be blocked\n ";
			counter--;
			UserName = IsInputValid::ReadString("please enter valid UserName");
			Password = IsInputValid::ReadString("please enter valid password");
			User = ClsUser::Find(UserName, Password);

		}
		 if (counter >1)
		{
			system("cls");
			CurrentUser = User;
			_LoginRegisterTmeAndDateToLineAndSaveItToFile();
			ClsMainScreen::ShowMainMenu();
			return true;
		}
		 else
		 {
			 cout << "you have been blocked because you have enter your information wrong for 3 times \n";
			 return false;
		 }
		 return false;
	
	}

};


