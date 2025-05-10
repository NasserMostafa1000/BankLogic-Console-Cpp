#pragma once
#include "clsDate.h"
#include "random"
class ClsUtil
{
public:
	static void SRand()
	{
		srand(unsigned(time(NULL)));
	}
	static short RandomNumber(short from, short to)
	{
		return rand() % (to - from + 1) + from;
	}
	enum CharType
	{
		SmallChar = 1, BigLetter = 2, punctuation = 3, Mix = 4
	};
	static char GenerateRandomCharacter(CharType EnUserChar)
	{

		switch (EnUserChar)
		{
		case ClsUtil::SmallChar:
			return	 char(ClsUtil::RandomNumber(97, 122));
			break;
		case ClsUtil::BigLetter:
			return	 char(ClsUtil::RandomNumber(65, 90));
			break;
		case ClsUtil::punctuation:
			return	 char(ClsUtil::RandomNumber(33, 47));
			break;
		case ClsUtil::Mix: {
			short num = RandomNumber(1, 3);
			CharType type1 = CharType(num);
			return	 ClsUtil::GenerateRandomCharacter(type1);
		}
						 break;
		default:
			return '\0';
			break;
		}
	}
	static string GenerateWord(CharType WordType, short LetterOfTheWord) {
		std::string word = "";
		for (short i = 0; i < LetterOfTheWord; i++) {
			switch (WordType) {
			case CharType::SmallChar: {
				word += static_cast<char>(RandomNumber(97, 122));
				break;
			}
			case CharType::BigLetter: {
				word += static_cast<char>(RandomNumber(65, 90));
				break;
			}
			case CharType::punctuation: {
				word += static_cast<char>(RandomNumber(33, 47));
				break;
			}
			case CharType::Mix: {
				short num = RandomNumber(1, 3);
				CharType type = static_cast<CharType>(num);
				word += GenerateWord(type, LetterOfTheWord);
				break;
			}
			default:
				return "";
			}
		}
		return word;
	}
	static string GenerateKey(CharType KeyType, short LetterOfTheWOrd)
	{
		string Key = "";
		switch (KeyType)
		{
		case ClsUtil::SmallChar:
		{
			Key += GenerateWord(ClsUtil::SmallChar, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::SmallChar, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::SmallChar, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::SmallChar, LetterOfTheWOrd);

		}
		break;
		case ClsUtil::BigLetter: {
			Key += GenerateWord(ClsUtil::BigLetter, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::BigLetter, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::BigLetter, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::BigLetter, LetterOfTheWOrd);
		}
							   break;
		case ClsUtil::punctuation: {
			Key += GenerateWord(ClsUtil::punctuation, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::punctuation, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::punctuation, LetterOfTheWOrd) + "-";
			Key += GenerateWord(ClsUtil::punctuation, LetterOfTheWOrd);
		}
								 break;
		case ClsUtil::Mix: {
			short MixType = ClsUtil::RandomNumber(1, 3);
			CharType Type = CharType(MixType);
			GenerateKey(Type, LetterOfTheWOrd);
		}
						 break;
		default:
			break;
		}
		return Key;
	}
	static string GenerateKeys(CharType KeyType, short Quantity)
	{
		for (short i = 0; i <= Quantity; i++)
		{
			// the word will be 4 char by default
			cout << GenerateKey(KeyType, 4) << endl;
		}
	}
	static void Swap(short& num1, short& num2) {
		short temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(double& num1, double& num2) {
		double temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(int& num1, int& num2) {
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(float& num1, float& num2) {
		float temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static void Swap(long int& num1, long int& num2) {
		long int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	static string numberToText(long int number)
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
	static void Swap(string& String1, string& string2) {
		string temp = String1;
		String1 = string2;
		string2 = temp;
	}
	static void SwapDates(ClsDate& date1, ClsDate date2)
	{
		ClsDate TempDate;
		TempDate.Day = date1.Day;
		TempDate.Year = date2.Year;
		TempDate.Month = date2.Month;
		date1.Day = date2.Day;
		date1.Year = date2.Year;
		date1.Month = date2.Month;
		date2.Day = TempDate.Day;
		date2.Month = TempDate.Month;
		date2.Year = TempDate.Year;



	}
	static void ShuffleArray(int Arr[], short Length) {
		srand(time(NULL)); // تهيئة بذرة لتوليد أرقام عشوائية

		for (short i = 0; i < Length; i++) {
			short randomIndex = rand() % Length; // توليد فهرس عشوائي في النطاق من 0 إلى Length-1
			// قم بتبديل العنصر الحالي مع العنصر العشوائي المختار
			int temp = Arr[i];
			Arr[i] = Arr[randomIndex];
			Arr[randomIndex] = temp;
		}
	}
	static void ShuffleArray(string Arr[], short Length) {
		srand(time(NULL)); // تهيئة بذرة لتوليد أرقام عشوائية

		for (short i = 0; i < Length; i++) {
			short randomIndex = rand() % Length; // توليد فهرس عشوائي في النطاق من 0 إلى Length-1
			// قم بتبديل العنصر الحالي مع العنصر العشوائي المختار
			string temp = Arr[i];
			Arr[i] = Arr[randomIndex];
			Arr[randomIndex] = temp;
		}
	}
	static void FillArrWithRandomNumber(int Arr[], short Length, short NumbersFrom, short NumbersTo)
	{
		for (int arr = 0; arr < Length; arr++)
		{
			Arr[arr] = ClsUtil::RandomNumber(NumbersFrom, NumbersTo);
		}
	}
	static void FillArrWithRandomWords(string Arr[], short Length, CharType TypeOfTheWord, short HowManyChar)
	{
		for (int arr = 0; arr < Length; arr++)
		{
			Arr[arr] = ClsUtil::GenerateWord(TypeOfTheWord, HowManyChar);
		}
	}
	static void FillArrWithKeys(string Arr[], short Length, CharType TypeOfTheWord, short HowManyChar)
	{
		for (int arr = 0; arr < Length; arr++)
		{
			Arr[arr] = ClsUtil::GenerateKey(TypeOfTheWord, HowManyChar);
		}
	}
	static void Tap(short Tap)
	{
		for (short i = 1; i <= Tap; i++)
		{
			cout << " ";
		};
	}

	static string encryption(string nm,short key=2)
	{
		string Text=nm;
		for (char i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - key);
		}
		return Text;
	}

	static string decryption(string Text,short key=2)
	{
	
		string Xm = Text;
		for (char i = 0; i < Text.length(); i++)
		{
			Xm[i] = char((int)Xm[i]+key);
		}
		return Xm;
	}
};

