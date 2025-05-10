#pragma once
#include <iostream>
#include<string>
#include "ClsString.h"
#include <fstream>
#include "ClsPerson.h"
#include "IsInputValid.h"
#include <vector>
using namespace std;
class ClsBankClient :public ClsPerson
{
private:
	string _AccountNumber, _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;
	enum _EnMode
	{
		EmptyMode = 0, UpdateMode = 1, EnAddNew = 2
	};
	_EnMode _Mode;
	static ClsBankClient _ReturnLineToClientClass(string& Line)
	{
		//تحويل السطر القادم ن من الفايل او الداتا بيز  الي هيكل  (كلاس) من نوع عميل بنك
		vector<string>VecLine = ClsString::split(Line, "##");
		return ClsBankClient(_EnMode::UpdateMode, VecLine[0], VecLine[1], VecLine[2], VecLine[3], stof(VecLine[4]),
			VecLine[5], VecLine[6], VecLine[7]);
	}
	static ClsBankClient _GetEmptyClientObject()
	{
		//هذه الكود يستخدم مع فانكشن فايند كلاينت اي اوجد عميل ,اذا
		//  تم ايجاد العميل يقوم بارجاعه في نتيجه الفانكشن وان لم يجده
		//  يقوم بارجاع هذا الكلاس, لكي اذا تم عمل سيف اي حفظ علي نفس الكلاس
		//  يعطيه ايرور لانه في الوضع الفاضي اي لم يدخل بيانات
		
		return ClsBankClient(_EnMode::EmptyMode, "", "", "", "", 0, "", "", "");

	}
	static vector<ClsBankClient>_LoadAllClientFromFile()
	{
		// تحميل جميع البيانات الموجود في الداتا بيز او الفايل الي فيكتور من نوع كلاس
		vector<ClsBankClient>AllClient;
		fstream file;
		string Line;
		file.open("Client.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, Line))
			{
				AllClient.push_back(_ReturnLineToClientClass(Line));
			}
			file.close();
		}
		return AllClient;
	}
	static string _ReturnClassToLine(ClsBankClient& Client)
	{
		//هذه الفانكشن وظيفته هو تحويل الكلاس الي سطر ليكون جاهز للحفظ في الملف
		string Line = "";
		Line += Client.FirstName() + "##";
		Line += Client.ClsPerson::SecondName() + "##";
		Line += Client._AccountNumber + "##";
		Line += Client.PinCode + "##";
		Line += to_string(Client._AccountBalance) + "##";
		Line += Client.ClsPerson::Id() + "##";
		Line += Client.ClsPerson::phone() + "##";
		Line += Client.ClsPerson::Email();
		return Line;
	}
	static void _SaveAllClientsToFile(vector<ClsBankClient>& VecAllClient)
	{
		//هذه الوظيفه تقوم باخذ الفيكتور وحفظه الي لملف
		fstream file;
		file.open("Client.txt", ios::out);
		if (file.is_open())
		{
			for (ClsBankClient& s : VecAllClient)
			{
				if (s._MarkForDelete == false)
				{
					file << _ReturnClassToLine(s) << endl;
				}
			}
		}
		file.close();
	}
	void _Update()
	{
		//هذا الفاكشن هو وظيفته اخذ الفيكتور لجميع العملاء
		//  وبحث عن رقم الاكونت المطابق للكلاس الحالي ثم حفظه مجداا بعد اي تحديثات حدثت
		vector<ClsBankClient>VecAllClient = _LoadAllClientFromFile();
		for (ClsBankClient& SingleClient : VecAllClient)
		{
			//هذا الفانكشن يحفظ الكلاس من خلال الاوبجكت الذي تم استدعائه منه
			if (SingleClient._AccountNumber == _AccountNumber)
			{
				SingleClient = *this;
				break;

			}
		}
		_SaveAllClientsToFile(VecAllClient);
	}
 	void _AddNewClient()
	{
		//هذا الفانكشن يحفظ الكلااس الذي تم استدعاء هذه الميثود عن طريقه
		fstream file;
		file.open("Client.txt", ios::app);
		if (file.is_open())
		{
			file << _ReturnClassToLine(*this) << endl;
			file.close();
		}
	}
public:
	ClsBankClient(_EnMode Mode, string FirstName, string SecondName, string AccountNumber, string PinCode, double AccountBalance,
		string Id, string Phone, string Email) :ClsPerson(Id, Phone, Email, FirstName, SecondName)
	{
		// تعريف كونستراكتور ياخذ ما نحتاجه لبناء عميل البنك
		_Mode = Mode;
		_AccountBalance = AccountBalance;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
	}
	bool IsEmpty()
	{
		//تستخدم لتتاكد ان الاوبجت الذي استدعت هذه الميثود هي فارغه ام لا
		return _Mode=_EnMode::EmptyMode;
	}
	// property Get
	string getAccountNumber()
	{
		//property get private Members and cancel abstraction concept
		//ملكيه الحصول علي الاعضاء الخاصه والغاء مبدا التجريد
		// اي سيتم ايجاد رقم الحساب بمجرد استدعاء اوبجكت من هذا الكلاس
		return _AccountNumber;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	// property Set
	void SetPinCode(string PinCode)
	{
		this->_PinCode = PinCode;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	void SetAccountNumber(string AccountNumber)
	{
		_AccountNumber = AccountNumber;
	}
	_declspec(property (get = GetAccountBalance, put = SetAccountBalance))double AccountBalance1;
	//void print()
	//{
	//	cout << "          client card\n";
	//	cout << "_______________________________________________________\n";
	//	cout << "   first name  : " << FirstName() << endl;
	//	cout << "   second name : " << SecondName() << endl;
	//	cout << "   Full name   : " << FullName() << endl;
	//	cout << "   Email       : " << Email() << endl;
	//	cout << "   Phone       : " << phone() << endl;
	//	cout << "   acc Number  : " << _AccountNumber << endl;
	//	cout << "   acc Balance : " << _AccountBalance << endl;
	//	cout << "   password    : " << _PinCode << endl;
	//}
	static ClsBankClient Find(string AccountNumber)
	{
		//فانكشن جد عميل بواسطه رقم الحساب اذا تم ايجاده يقوم
		//  بارجاع العميل في وضع التحيث اي يمكنك تحديث اي شئ فيه___وان لم يجد فسيتم
		//  ارجاع اوبجت في وضع الفراغ لكي لا يتم حفظه في الملف
		fstream file;
		string Line;
		file.open("Client.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, Line))
			{
				ClsBankClient CurrentClient = _ReturnLineToClientClass(Line);
				if (CurrentClient._AccountNumber == AccountNumber)
				{
					file.close();
					return CurrentClient;
				}
				
			}
		}
		return _GetEmptyClientObject();
	}
	static ClsBankClient Find(string AccountNumber, string PinCode)
	{
		// its as same as the function on above but its validate on the pin code too with account number
		fstream file;
		string Line;
		file.open("Client.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, Line))
			{
				ClsBankClient CurrentClient = _ReturnLineToClientClass(Line);
				if (CurrentClient._AccountNumber == AccountNumber && CurrentClient.PinCode == PinCode)
				{
					file.close();
					return CurrentClient;
				}
				else {
					_EnMode::UpdateMode;
				}
			}
		}
		return _GetEmptyClientObject();
	}
	static bool IsThisClientAlreadyExists(string AccountNumber)
	{
		ClsBankClient Client = Find(AccountNumber);
		return (Client._AccountNumber == AccountNumber);
	}
	enum EnSaveResult
	{
		// here is the result of saving
		EnSavingSuccess = 0, EnSavingFailEmptyObject = 1, EnSavingFailAccountNumberExists=2
	};
	EnSaveResult Save()
	{
		//عند استدعاء هذه الميثود مع اوبجت تقوم بالتحقق علي الوضع عشان لو
		//  فاضي ترسل ان العمليه فشلت او في حاله اضافه عضو جديد تفحص ان كان رقم الحساب موجود من قبل 
		switch (_Mode)
		{
		case ClsBankClient::EmptyMode: {
			if (IsEmpty())
			{
				return EnSavingFailEmptyObject;
			}
		}
			break;
		case ClsBankClient::UpdateMode:
		{
			_Update();
			return EnSavingSuccess;
		}
			break;
		case EnAddNew:
		{
			if (IsThisClientAlreadyExists(_AccountNumber))
			{
				return EnSavingFailAccountNumberExists;
			}
			else
			{
				_AddNewClient();
				_Mode = _EnMode::UpdateMode;
				return EnSavingSuccess;
			}
			
		}
		//default:
			//break;
		}
	}
	static ClsBankClient GetAddNewMode(string& accountnumber)
	{
		// هنا تستخدم قبل ملئ بيانات العميل يجب استخدامها ليتم حفظ العميل الجديد بامان
		return ClsBankClient(_EnMode::EnAddNew, "", "", accountnumber, "", 0, "", "", "");
	}
	bool DeleteClient()
	{
		//هنا نحذف العميل الموجود في هذا الاوبجكت
		vector<ClsBankClient>AllClients = ClsBankClient::_LoadAllClientFromFile();
		for (ClsBankClient &SingleClient : AllClients)
		{
			if (SingleClient._AccountNumber == _AccountNumber)
			{
				SingleClient._MarkForDelete = true;
				break;
			}
		}
		_SaveAllClientsToFile(AllClients);
		*this = _GetEmptyClientObject();
		return true;

	}
	static vector<ClsBankClient>_LoadAllClientFromFil()
	{
		return _LoadAllClientFromFile();
	}
	static double TotalBalance()
	{
		//هنا كل رصيد العملاء
		double SumOfBalance = 0;
		vector<ClsBankClient>AllClients = _LoadAllClientFromFile();
		for (ClsBankClient &SingleClient : AllClients)
		{
			SumOfBalance+=SingleClient.AccountBalance1;
		}
		return SumOfBalance;
	}
	void Deposit(double Amount)

	{
		//هنا وظيفه تاخد المبلغ الموده وتضعه في الملف او الداتا بيز علي الرصيد السابق
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		//هنا نسحب من مال العميل الموجود علي التطبيق
		if (Amount < _AccountBalance)
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
		else
		{
			return false;
		}
		
	}
};

