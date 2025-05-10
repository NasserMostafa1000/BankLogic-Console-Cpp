#pragma once

#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <fstream>
#include "naserLib.h"
#include "string.h"
#include <ctime>
using namespace std;
//#include <string>
static vector <string>splitString(string s1, string distance)
{
	//return string to vector
	vector<string>FillVectorWithString;
	string word = "";
	short int pos = 0;
	while ((pos = s1.find(distance)) != std::string::npos)
	{
		word = s1.substr(0, pos);
		if (word != "")
		{
			FillVectorWithString.push_back(word);
			s1.erase(0, pos + distance.length());
		}

	}
	if (!s1.empty()) {
		FillVectorWithString.push_back(s1);

	}
	return FillVectorWithString;
}

string numberToText(long int number)
{
	if (number == 0)
	{
		return "";
	}
	if (number >= 1 && number <= 19)
	{
		string arr[] = { "","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen"
		 ,"fifteen","sixteen","seventeen","eighteen","nineteen" };
		return arr[number] + " ";
	}
	if (number >= 20 && number <= 99)
	{
		string arr[] = { "","","twenty","thirty","forty","fifty" ,"sixty","seventy","eighty" ,"ninety" };
		return arr[number / 10] + " " + numberToText(number % 10);
	}
	if (number >= 100 && number <= 199)
	{
		return "one hundred " + numberToText(number % 100);
	}
	if (number >= 200 && number <= 999)
	{
		return  numberToText(number / 100) + " hundreds " + numberToText(number % 100);
	}
	if (number >= 100 && number <= 1999)
	{
		return "one thousand " + numberToText(number % 1000);
	}
	if (number >= 2000 && number <= 999999)
	{
		return numberToText(number / 1000) + " thousand " + numberToText(number % 1000);
	}
	if (number >= 1000000 && number <= 1999999)
	{
		return "one million " + numberToText(number % 1000000);
	}
	if (number >= 2000000 && number <= 999999999)
	{
		return numberToText(number / 1000000) + " million " + numberToText(number % 1000000);
	}
	if (number >= 1000000000 && number <= 1999999999)
	{
		return "one billion " + numberToText(number % 1000000000);
	}
	else
	{
		return numberToText(number / 1000000000) + " Billion " + numberToText(number % 1000000000);
	}
}
bool isvowel(char ch1)
{
	ch1 = tolower(ch1);
	return ch1 == 'a' || ch1 == 'i' || ch1 == 'u' || ch1 == 'o' || ch1 == 'e';
}
string Envertallcharofsentences(string s1)
{
	//#include <string>
	for (int i = 0; i < s1.length(); i++)
	{
		isupper(s1[i])?tolower(s1[i]):toupper(s1[i]);
	}
	return s1;
}
string JoinString(vector<string>joinString, string dilm)

{
	//تحويل الفيكتور الي جمله استرينج
	//return vector to string
	string sentence = "";
	for (string& n : joinString)
	{
		sentence += n + dilm;
	}
	return sentence.substr(0, sentence.length() - dilm.length());

}
string upperAllString(string s1)
{
	for (char i = 0; i < s1.length(); i++)
	{
		s1[i] = toupper(s1[i]);

	}
	return s1;
}
string lowerAllString(string s1)
{
	for (char i = 0; i < s1.length(); i++)
	{
		s1[i] = tolower(s1[i]);

	}
	return s1;
}
string trimRight(string s1)
{
	for (char i = 0; i < s1.length(); i++) {
		if (s1[i] != ' ') {
			return s1 = s1.substr(i, s1.length());
		}
	}
	return "";

}
string trimLeft(string s1)
{
	for (char i = s1.length() - 1; i >= 0; i--) {
		if (s1[i] != ' ') {
			return s1 = s1.substr(0, i + 1);
		}
	}
	return "";
}
string reverseALlWordsInString(string s1)
{
	string s2 = "";
	vector<string>vWords = splitString(s1, " ");
	vector<string>::iterator iter = vWords.end();
	while (iter != vWords.begin()) {
		iter--;
		s2 += *iter + " ";
	}

	return s2 = s2.substr(0, s2.length() - 1);
}
string trim(string s1) {
	return trimRight(trimLeft(s1));
}
string replaceWordOnSentence(string s1, string TheWordWillChange,string dillm, string TheWordToInsert, bool matchCase = true)
{
	vector<string>vsentence = splitString(s1, dillm);
	for (string& s : vsentence)
	{
		if (matchCase)
		{
			if (s == TheWordWillChange)
			{
				s = TheWordToInsert;
			}
		}
		else
		{
			if (lowerAllString(s) == lowerAllString(TheWordWillChange))
			{
				s = TheWordToInsert;
			}
		}
	}
	return JoinString(vsentence, dillm);

}
string removePunctuation(string s1)
{
	string s2 = " ";
	for (char i = 0; i < s1.length(); i++)
	{
		if (!ispunct(s1[i]))
		{
			s2 += s1[i];
		}
		else
			s2 += " ";

	}
	return s2;
}
short int RandomNumber(short int from, short int to)
{
	//#include <cstdlib>
	short int  randNumber;
	randNumber = rand() % (to - from + 1) + from;
	return randNumber;

}
short countTheVowelLettersOnString(string s1)
{
	short count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (isvowel(s1[i])) {
			count++;
		}
	}
	return count;
}
char convertChar(char s1)
{
	return isupper(s1) ? tolower(s1) : toupper(s1);
}
