#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include "Global.h"
#include "clsDate.h"
#include "ClsUser.h"
using namespace std;
class ClsTheStaticScreen
{
	//ramy##salama##1966##32126##9000.000000##13213##098098##ramysalama122@gmail.com
public:
	
	static void PrintMinuScreen(string menu) {
		cout << "                 Owner: MR Nasser Mostafa.\n";
		cout << "                ________________________________________________________________________\n";
		cout << "                                  "<<menu<< endl;
		cout << "                ________________________________________________________________________\n";
		
			cout << "                                        user : " << CurrentUser.FullName() << endl;
		
		Date CurrentDate= GetSystemDate();
		cout << "                                             " << CurrentDate.Day << "/" << CurrentDate.Month << "/" << CurrentDate.Year << "\n\n";

	}
};

