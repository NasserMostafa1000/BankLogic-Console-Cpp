#pragma once
#include "ClsTheStaticScreen.h"
#include "ClsUser.h"
#include "ClsUtil.h"
class ClsShowUserList:private ClsTheStaticScreen
{

static	vector<ClsUser>_AllUser()
	{
		vector<ClsUser>AllClient = ClsUser::LoadAllUserFromFile();
		return AllClient;
	}
	static void _printingTheRowOfTheSingleUser(ClsUser &USerTOPrint)
	{
		cout << setw(37) << left << USerTOPrint.FullName() <<
			setw(18) << "|" << USerTOPrint.phone() <<
			setw(12) << "|" << USerTOPrint.UserName <<
			setw(19) << "|" << ClsUtil::encryption( USerTOPrint.Password) <<
			setw(14) << "|" << USerTOPrint.Permission <<
			setw(20) << "|" << endl;
	}
public:
	static void ShowUserList()
	{
		ClsTheStaticScreen::PrintMinuScreen("Show User List Menu");
		cout <<setw(37)  <<left  <<"   _________________________________________________________________________________________________\n";
		cout << setw(37) << left << "  fullName          |   phone    |     User Name    |   password   |permission|       Email       | \n";
	    cout << setw(37) << left <<  " _________________________________________________________________________________________________\n";
		//after printing the header we should CAll (_LoadAllUsersFromTheBaseClass) methods that will give you a vector with all data
		vector<ClsUser>AllUsers = _AllUser();
		//we will user for each to get all users from a to z
		for (ClsUser& TheCurrentClient : AllUsers)
		{
			// we will call the private method that take the all clients client by client from client a to z.
			_printingTheRowOfTheSingleUser(TheCurrentClient);

		}
	 }
};

