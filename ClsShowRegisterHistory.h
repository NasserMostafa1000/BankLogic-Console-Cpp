#pragma once
#include "ClsTheStaticScreen.h"
class ClsShowRegisterHistory:ClsTheStaticScreen
{

private:
	string _dateAndTime, _userName, _Password,_Permisiion;

	static ClsShowRegisterHistory _ReturnLineTostruct(string Line)
	{
		vector<string>AllRegistration=ClsString::split(Line,"##");
		ClsShowRegisterHistory TheCurrentUserInfo;
		TheCurrentUserInfo._dateAndTime = AllRegistration.at(0);
		TheCurrentUserInfo._userName = AllRegistration.at(1);
		TheCurrentUserInfo._Password=ClsUtil::encryption(TheCurrentUserInfo._Password = AllRegistration.at(2));

		TheCurrentUserInfo._Permisiion = AllRegistration.at(3);

		return TheCurrentUserInfo;

	}
	static vector<ClsShowRegisterHistory> _GetAllHistoryFromFile()
	{
		vector<ClsShowRegisterHistory>AllRegistration;
		fstream file;
		string Line;
		file.open("RegistertionTime&date.txt", ios::in);//read mode
		if (file.is_open())
		{
			while (getline(file, Line))
			{
				AllRegistration.push_back(_ReturnLineTostruct(Line));
			}
			file.close();
			}
		return AllRegistration;
	}
	static void PrintSingleRegistrationDateForAllVector(ClsShowRegisterHistory &RegistrationTimeToPrint)
	{
		cout << setw(37) << left << "                                              \n" << RegistrationTimeToPrint._dateAndTime << "\t\t\t\t\t"
			<< RegistrationTimeToPrint._userName << "\t\t" << RegistrationTimeToPrint._Password << "\t\t\t\t"<<endl<< RegistrationTimeToPrint._Permisiion;;

	}
public:
	static	void ShowRegistrationHistory()
	{

		ClsTheStaticScreen::PrintMinuScreen("registration history menu");
		cout << setw(37) << left << "                                      ______________________________________________________________________ \n";
			cout << setw(37) << left << "                                       date&time           |  UserName    |   Password     |permission         \n";
		cout << setw(37) << left << "                                      _______________________________________________________________________        \n";
		 
		vector<ClsShowRegisterHistory>All = _GetAllHistoryFromFile();

		for (ClsShowRegisterHistory single : All)
		{
			PrintSingleRegistrationDateForAllVector(single);
		}


    }
};

