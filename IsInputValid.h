#pragma once
#include <iostream>
#include <string>
#include "ClsDate.h"
using namespace std;
class IsInputValid
{
	public:
		template <typename T>
	static bool IsNumberBetween(T number, T from, T to)
	{
		return (number > from && number < to);
	}
	//to call the function with int numbers ISNumberBetween<int>(20,1,8);
	static bool IsDateBetween(ClsDate &TheDate, ClsDate& DateFrom, ClsDate &DateTo)
	{
		//The Date should be after than date from and before than date 2
		return (ClsDate::IsDate1BeforeDate2(TheDate, DateTo) && ClsDate::IsDate1AfterDate2(TheDate, DateFrom));
	}
	static int ReadIntNumber(string message) {
		int number;

		while (true) {
			std::cout << "Please enter a number: ";
			std::cin >> number;

			if (std::cin.fail()) {
				std::cout << message << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}

		return number;
	}
	template <typename T>
	static T ReadNumberBetween1(string message, T from, T to) {
		short number;
		do {
			std::cout << "\t\t\t\t\tenter number from " << from << " To " << to << endl;;
			std::cin >> number;
			if (std::cin.fail() || number < from || number > to) {
				std::cout << "\t\t\t\t\tInvalid input. " << message << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				break;
			}
		} while (true);

		return number;
	}
	template <typename T>
	static T ReadNumber(const std::string& message) {
		double number;

		while (true) {
			std::cout << message;
			std::cin >> number;

			if (std::cin.fail()) {
				std::cout << "Invalid input. " << message << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}

		return number;
	}
	static char ReadChar(string message)
	{
		char TheChar;
		cout << message;
		cin >> TheChar;
		return TheChar;
	}
	static float ReadFloatNumber(const std::string& message) {
		float number;

		while (true) {
			std::cout << message;
			std::cin >> number;

			if (std::cin.fail()) {
				std::cout << "Invalid input. " << message << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				break;
			}
		}

		return number;
	}
	static string ReadString(string message)
	{
		string input;
		cout << message;

		// ???? ?????? ?? ??? ???????
		while (true)
		{
			(cin>> input);

			// ?????? ?? ?? ??????? ??? ??????

			if (!input.empty())
			{
				break;
			}

			// ????? ???????? ??? ??????? ??? ????
			cout << "Invalid input. Please enter a non-empty string: ";
		}

		return input;
	}
	static bool IsValidDate(ClsDate& date)
	{
		return ClsDate::IsThisValidDate(date);
	}
	static string ReadLine(string message)
	{
		string Line;
		cout << message << endl;
		getline(cin >> ws, Line);
		return Line;
	}
};

