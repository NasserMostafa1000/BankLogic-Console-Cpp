//Nasser ELbarbary for programming@?
#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include "string.h"
#include <fstream>
#include <ctime>
using namespace::std;
//files
void printFileContent(string filename)
{
	fstream file;
	file.open(filename, ios::out | ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();

	}



}
void loadDataFromfileToVector(string fileName, vector<string>& vData)
{

	fstream file;
	file.open(fileName, ios::out | ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			vData.push_back(line);
		}
		file.close();

	}
}
void loadDataFromVectorToFile(string fileName, vector<string>& vData)
{
	fstream file;
	file.open(fileName, ios::out | ios::app);
	if (file.is_open())
	{
		for (string& names : vData)
		{
			file << names << endl;
		}
		file.close();
	}
}
void deleteRecordFromFile(string fileName, string record)
{
	vector<string>vData;
	loadDataFromfileToVector(fileName, vData);
	for (string& n : vData)
	{
		if (n == record) {
			n = "";
		}

	}
	loadDataFromVectorToFile(fileName, vData);


}
void updateRecordToFile(string fileName, string Record, string updateRecord)
{
	vector<string>vName;
	loadDataFromfileToVector(fileName, vName);
	for (string& line : vName)
	{
		if (line == Record) {
			line = updateRecord;
		}
		loadDataFromVectorToFile(fileName, vName);
	}




}
void getTheLocalTime()
{
	//#pragma warning (disable:4996)

	time_t t = time(0);
	char* dt = ctime(&t);
	cout << "local date time is : " << dt << endl;
}
void giveMeUTCTime()
{
	//#pragma warning (disable:4996)

	time_t t = time(0);
	char* dt = ctime(&t);
	cout << "the local time is : " << dt << endl;
	tm* gmtm = gmtime(&t);
	dt = asctime(gmtm);
	cout << "The UTC Time Is : " << dt << endl;;
}
void printAllFirstLetterOnEachWord(string s1)
{
	bool isfirstletter = true;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != ' ' && isfirstletter) {
			cout << s1[i];
		}
		isfirstletter = (s1[i] == ' ') ? true : false;
	}


}




