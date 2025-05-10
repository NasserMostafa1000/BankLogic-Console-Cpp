#pragma once
#include <fstream>
#include "ClsPerson.h"
#include <string>
#include <iostream>
#include "IsInputValid.h"
#include "ClsString.h"
#include <vector>
#include "ClsUtil.h"
using namespace std;

class ClsUser: public ClsPerson
{
private:
	enum _EnMode
	{
		emtyMode=0,UpdateMode=1,AddNewMode=2
	};
	_EnMode _Mode;
	string _UserName, _PassWord;
	int _Permission;
	bool _MarkForDelete=false;
	static ClsUser _ReturnLineToUserClass(string Line)
	{
		vector<string> UserData = ClsString::split(Line, "##"); 
			return ClsUser(_EnMode::UpdateMode, UserData.at(0), UserData.at(1), UserData.at(2), UserData.at(3), UserData.at(4),ClsUtil::decryption(UserData.at(5)), stoi(UserData.at(6)));
		
		//else if (UserData.size()<7)
		//{
		//	// يمكنك إضافة رسالة تحذير هنا
		//	cout << "Warning: Invalid data format in line: " << Line << endl;
		//	// إرجاع كائن فارغ أو قيمة افتراضية حسب احتياجاتك
		//	return _GetEmptyObject();
		//}
	}
	static ClsUser _GetEmptyObject()
	{
		return ClsUser(_EnMode::emtyMode, "", "", "", "", "", "",0);
	}
	 bool _IsEmpty()
	{
		return _Mode == ClsUser::emtyMode;

	}
	static vector<ClsUser> _LoadAllUserFromFile()
	{
		vector<ClsUser>AllClient;
		fstream file;
		string Line;
		file.open("User.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, Line))
			{
				AllClient.push_back(_ReturnLineToUserClass(Line));
			}
			file.close();
		}
		return AllClient;
	}
	string _ReturnClassToLine(ClsUser &User)
	{
		//naser##mostafa##nasermostafa@gmail.com##mostafa mostafa##2002##jhgjh##0
		string Line = "";
		Line += User.FirstName() + "##";
		Line += User.SecondName() + "##";
		Line += User.Email() + "##";
		Line += User.phone() + "##";
		Line += User.UserName + "##";
		//string password = ;
	    Line += ClsUtil::encryption(User.Password)+"##";
        Line += to_string(User.Permission);

		return Line;
	}
	void _SaveUsersVectorToFile(vector<ClsUser>& AllUser)
	{
		fstream file;
		file.open("User.txt",ios::out);
		if (file.is_open())
		{
			for (ClsUser& s : AllUser)
			{
				if (s._MarkForDelete==false)
				{
					file << _ReturnClassToLine(s) << endl;
				}
			}
			
		}
		file.close();
	}
	void _Update()
	{
		vector<ClsUser>AllUser = _LoadAllUserFromFile();
		for (ClsUser &SingleUser : AllUser)
		{
			if (this->UserName == SingleUser.UserName)
			{
				SingleUser=*this;
				break;
			}
		}
		_SaveUsersVectorToFile(AllUser);
	}
	void _AddNew()
	{
		fstream file;
		file.open("User.txt",ios::app);
		if (file.is_open())
		{
			file << _ReturnClassToLine(*this) << endl;
			file.close();
		}
		
	}
public:
	ClsUser(_EnMode Mode, string FirstName, string SecondName, string Email, string Phone, string UserName, string Password, int Permission)
		:ClsPerson("2020", Phone, Email, FirstName, SecondName)
	{
		_Mode = Mode;
		_UserName = UserName;
		_PassWord = Password;
		_Permission = Permission;
	}
	//property set
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	void SetPassword(string password)
	{
		_PassWord = password;
	}
	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}
	void SetForDelete()
	{
		 _MarkForDelete = true;
	}
	//property Get
	string GetUserName()
	{
		return _UserName;
	}
	string GetPassword()
	{
		return _PassWord;
	}
	int GetPermission()
	{
		return _Permission;
	}
	//property set and get cant provide you to set the variable out of the class with = unless using class declspec 
	_declspec(property (get = GetPermission, put = SetPermission))int Permission;
	_declspec(property (get = GetUserName, put = SetUserName))string UserName;
	_declspec(property (get = GetPassword, put = SetPassword))string Password;

static	ClsUser Find(string UserName)
	{
		fstream file;
		string GetLine;
		
		file.open("User.txt",ios::in);
		if (file.is_open())
		{
			while (getline(file, GetLine))
			{
			ClsUser currentUser=_ReturnLineToUserClass(GetLine);
			if (currentUser.UserName == UserName)
			{
				file.close();
				return currentUser;
			}
		
			}
		
		}
	return	_GetEmptyObject();
	}
 bool IsEmpty()
{
	return _Mode == _EnMode::emtyMode;
}
	static ClsUser Find(string UserName,string &Password)
	{
		fstream file;
		string GetLine;

		file.open("User.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, GetLine))
			{
				ClsUser CurrentUser = _ReturnLineToUserClass(GetLine);
				if (CurrentUser.UserName == UserName&&CurrentUser.Password==Password)
				{
					
					file.close();
					return CurrentUser;
				}

			}

		}
		return	_GetEmptyObject();
	}
	static bool IsUserNameAlreadyExists(string &UserName)
	{
		ClsUser CurrentClient=ClsUser::Find(UserName);
		return (CurrentClient.UserName == UserName);
	}
	enum EnSaveResult
	{
		EnSavingSuccess=1,EnSavingFailEmptyObject=2,EnSavingFailUserNameIsAlreadyExists=3
	};
	EnSaveResult Save()
	{
		switch (_Mode)
		{
		case ClsUser::emtyMode:
			if (_IsEmpty())
			{
				return EnSavingFailEmptyObject;
			}
			break;
		case ClsUser::UpdateMode:
		{
			_Update();
			return EnSavingSuccess;
		}
		break;
		case ClsUser::AddNewMode:
		{
			if (IsUserNameAlreadyExists(_UserName))
			{
				return EnSavingFailUserNameIsAlreadyExists;
			}
			else
			{
				_AddNew();
				_Mode = UpdateMode;
				return EnSavingSuccess;
			}
		}
		break;
		default:
			return EnSavingFailUserNameIsAlreadyExists; // يمكنك تغيير القيمة حسب تصميمك
			break;
		}
		return EnSavingFailUserNameIsAlreadyExists; // يمكنك تغيير القيمة حسب تصميمك

	}

	bool Delete()
	{
		vector<ClsUser>AllUser = ClsUser::_LoadAllUserFromFile();
		for (ClsUser &SingleUser : AllUser)
		{
			if (SingleUser.UserName==_UserName)
			{
				SingleUser._MarkForDelete = true;
				break;
			
			}
		}
		_SaveUsersVectorToFile(AllUser);
		*this = _GetEmptyObject();
		return true;
	}
	static ClsUser GetAddNewUserObject()
	{
		return ClsUser(AddNewMode, "", "", "", "", "", "", 0);
	}
	static vector<ClsUser> LoadAllUserFromFile()
	{
		return _LoadAllUserFromFile();
	}

};

