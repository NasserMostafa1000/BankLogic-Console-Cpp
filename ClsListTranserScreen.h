#pragma once
#include "ClsTheStaticScreen.h"
#include "ClsString.h"
class ClsListTranserScreen:ClsTheStaticScreen
{

private:
		string dateAndTime, SourceAcc, DisAcc, amount, SourceBalance, DisBalance, User;

	
	static ClsListTranserScreen _returnVectorToTransferInfo(string line)
	{
		vector<string>Line = ClsString::split(line, "##");
		ClsListTranserScreen info;
		info. dateAndTime=Line.at(0);
		info.SourceAcc = Line.at(1);
		info.DisAcc = Line.at(2);
		info.amount = Line.at(3);
		info.SourceBalance = Line.at(4);
		info.DisBalance = Line.at(5);
		info.User = Line.at(6);
		return info;
	}

	static vector<ClsListTranserScreen>_AllHistoryOfTransfer()
	{
		vector<ClsListTranserScreen>AllHistory;
		string Line;
		fstream file;
		file.open("TransferInfo.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, Line))
			{
				AllHistory.push_back(_returnVectorToTransferInfo(Line));
				 
			}
			file.close();
	
		}
		return AllHistory;
}
	static void _printing(ClsListTranserScreen& SingleInfo)
	{
		cout << SingleInfo.dateAndTime << setw(15) << "|" << SingleInfo.SourceAcc << setw(12) << "|" << SingleInfo.DisAcc << setw(11) << "|" << SingleInfo.amount << setw(12) << "|" << SingleInfo.SourceBalance << setw(12) << "|" <<
			SingleInfo.DisBalance << setw(10) << "|" << SingleInfo.User
			;
	};

public:

	static void ShowListTransfer()
	{
		ClsTheStaticScreen::PrintMinuScreen("Show History of Transfer List");
		vector<ClsListTranserScreen>All = _AllHistoryOfTransfer();
		cout << "____________________________________________________________________________________\n";
		cout << "  Date_Time    |     s.acc   |  d.acc  |    amount  |  s.balance |d.balance  |user \n";
		cout << "____________________________________________________________________________________\n";
		for (ClsListTranserScreen& Single : All)
		{
			_printing(Single);
		}
 


	}
};

