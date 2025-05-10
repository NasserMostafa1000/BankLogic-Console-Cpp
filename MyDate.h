#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <fstream>
#include "string.h"
#include <ctime>
#include "naserLib.h"
using namespace std;
//<vif>calendar
struct Date
{
	short Year, Month, Day;
};
struct Time
{
	int hours, minutes, seconds;
};
struct Period
{
	Date start, end;
};
short GetTheDay()
{
	cout << "please enter the day\n";
	short day;
	cin >> day;
	return day;
}
short GetTheMonth()
{
	cout << "please enter the month\n";
	short month;
	cin >> month;
	return month;
}
short GetTheYear()
{
	cout << "please enter the year\n";
	short month;
	cin >> month;
	return month;
}
bool IsLeapYear(short year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysOnTheMonth(short month, short year)
{
	if (month < 1 || month > 12)
	{
		return 0;
	}
	short arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? IsLeapYear(year) ? 29 : 28 : arr[month];
}
short EquationForGetNumberOfDayOnWeekList(short year, short month, short day)
{
	//<vif>calendar
	//معادله رياضيه تاتي برقم اليوم في الترقيم الاسبوعي من خلال رقم الشهر والسنه واليوم
	short a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = (month + (12 * a)) - 2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}
string PrintDayNameByDayOrder(short DayNumber)
{
	//هنا يدخل رقم اليوم في الترقيم الاسبوعي ويوخرج اسم اليوم
	string ArrDay[] = { "sun","mon","tue" ,"wens" ,"thu","fri","sat" };
	return ArrDay[DayNumber];


}
string PrintMonthName(short monthNumber)
{
	//هنا يدخل رقم الشهر ويوخرج اسم الشهر
	string ArrMonthsName[] = { "jan","feb","Mar","Aprl","may","jun","jul","aguast","sep","oct","nov","des" };
	return ArrMonthsName[monthNumber - 1];
}
short GetTheNumberOfDaysOnYear(short year)
{
	return IsLeapYear(year) ? 366 : 365;
}
int GetTheNumberOfHours(short year)
{
	return GetTheNumberOfDaysOnYear(year) * 24;
}
int GetTheNumberOfMinute(short year)
{
	return GetTheNumberOfHours(year) * 60;
}
int GetTheNumberOfSecond(short year)
{
	return  GetTheNumberOfMinute(year) * 60;
}
void PrintYearCalendar(short month, short year)
{
	//هنا يسال المستخدم عن السنه والشهر ويقوم بطباعه التقويم لهذا الشهر في هذه السنه


		//في الخطوه التاليه نستخدم فانكشن داي اوردر لنعرف كم رقم هذا اليوم في الترقيم(التقويم) الاسبوعي الذي يبدا من الحد الي السبت
	short NumberOfWeeksDayList = EquationForGetNumberOfDayOnWeekList(year, month, 1);
	short NumberOfManyDaysOnMonth = numberOfDaysOnTheMonth(month, year);
	printf("__________________%s_______________________\n", PrintMonthName(month).c_str());
	printf("  sun  mon  tue  wen  thu  fri  sat  \n");
	int i;
	for (i = 0; i < NumberOfWeeksDayList; i++)

		printf("     ");
	for (int j = 1; j <= NumberOfManyDaysOnMonth; j++)
	{
		printf("%5d", j);
		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	printf("\n__________________________________________\n");


}
bool IsThatLastDayOnMonth(short NumberOfDays,short month, short year)
{
	return (NumberOfDays == numberOfDaysOnTheMonth(month, year));
}
bool IsThatLastMonthOnYear(short month)
{
	return (month == 12);


}
short GetHowManyDaysFromDate(short year, short day, short Allmonths)
{
	short SumOfDaysOnMonth = day;
	for (short month = 1; month < Allmonths; month++)
	{
		SumOfDaysOnMonth += numberOfDaysOnTheMonth(month, year);
	}
	return SumOfDaysOnMonth;
}
bool IsItEndOfWeek(Date date)
{
	return EquationForGetNumberOfDayOnWeekList(date.Year, date.Month, date.Day) == 5;
}
bool IsItWeekEnd(Date &date)
{
	short numOfTheDay = EquationForGetNumberOfDayOnWeekList(date.Year, date.Month, date.Day);

	return numOfTheDay == 5 || numOfTheDay== 6;
}
bool IsItBusniessDay(Date &date)
{

	return !IsItWeekEnd(date);
}
bool IsDate1EqualDate2(Date &date1,Date &date2)
  { return  (date1.Year == date2.Year) ? ((date1.Month == date2.Month) ? ((date1.Day == date2.Day) ? true : false) : false) 
 : false;
 } 
bool IsDate1BeforeDate2(Date& date1,Date& date2) 
{ return  (date1.Year < date2.Year) ? true : ((date1.Year == date2.Year) ? (date1.Month < date2.Month ? true :
  (date1.Month == date2.Month ? date1.Day < date2.Day : false)) : false); }
bool IsDate1AfterDate2(Date &date1,Date &date2)
{
	return (!IsDate1BeforeDate2(date1,date2) && (!IsDate1EqualDate2(date1, date2)));
}
Date GetSystemDate()
{
	Date date;
	time_t t = time(0);
	tm* now = localtime(&t);
	date.Year = now->tm_year + 1900;
	date.Month = now->tm_mon + 1;
	date.Day = now->tm_mday;
	return date;
}
void increaseDayOnDate(short& year, short& month, short& day)
{

	if (month == 12 && IsThatLastDayOnMonth(day, month, year))
	{
		year++;
		month = 1;
		day = 1;
	}
	else if (day == numberOfDaysOnTheMonth(month, year))
	{
		day = 1;
		month++;
	}
	else {
		day++;
	}

}

int GetAgeByDays(Date &SystemDate, short &year, short &month, short &day)
// the date is data from user otherhand the system date.
{
	int sum = 0;
	while (SystemDate.Year < year || (SystemDate.Year == year && SystemDate.Month < month) || (SystemDate.Year == year && SystemDate.Month == month && SystemDate.Day < day)) {
		sum++;
		increaseDayOnDate(SystemDate.Year, SystemDate.Month, SystemDate.Day);
	}
	return sum;
}
enum MyEnum
{
	Before = -1, After = 1, equal = 0
};
 MyEnum CompareDates(Date &date1,Date &date2)
{

	if (IsDate1BeforeDate2(date1, date2))
	{
		return MyEnum::Before;
	}
	else if (IsDate1AfterDate2(date1, date2))
	{
		return MyEnum::After; 
	}
	else
		return MyEnum::equal;
}
 bool IsOverLapPeriod(Period& p1, Period& P2)
 {
	 return(CompareDates(P2.end, p1.start) == MyEnum::Before
		 ||
		 CompareDates(P2.start, p1.end) ==  MyEnum::After);
 }
 Date ReadFullDate()
 {
	 Date date1;
	 date1.Day = GetTheDay();
	 date1.Month = GetTheMonth();
	 date1.Year = GetTheYear();
	 return date1;
 }
 Period ReadPeriod()
 {
	 Period per;
	 cout << "please enter start date\n";
	 per.start = ReadFullDate();
	 cout << "\nplease enter end date\n";
	 per.end = ReadFullDate();
	 return per;
 }
 bool IsDateInPeriod(Date &date,Period &period)
 {
	 return !(CompareDates(date, period.start) == Before || CompareDates(date, period.end) == After);
}
 void SwapDates(Date &date1,Date &date2)
 {
	 Date TempDates;
	 TempDates.Year = date1.Year;
	 TempDates.Day = date1.Day;
	 TempDates.Month = date1.Month;
	 date1.Year = date2.Year;
	 date1.Month = date2.Month;
	 date1.Day = date2.Day;
	 date2.Year = TempDates.Year;
	 date2.Month = TempDates.Month;
	 date2.Day = TempDates.Day;

 }
 short DiffBetweenTwoDates(Date &date1, Date &date2, bool IncludeLastDay=true)
 {
	 //check is is date on this period
	 //that used when you have a room book and want to check if the new date is on the period room book
	 
	 int days = 0;
	 short falgSign = 1;
	 if (IsDate1AfterDate2(date1, date2))
	 {
		 SwapDates(date1, date2);
		 falgSign = -1;
	 }
	 while (IsDate1BeforeDate2(date1, date2))
	 {
		 days++;
		 increaseDayOnDate(date1.Year, date1.Month, date1.Day);
	 }

	 return (IncludeLastDay) ? ++days*falgSign : days*falgSign;
	 
 }
 short DiffBetweenTwoDates(Period &P1)
 {

	return  DiffBetweenTwoDates(P1.start, P1.end,true);
 }
 short PeriodLength(Period& P1)
 {
	 return DiffBetweenTwoDates(P1);

 }
 short countOverLabDays(Period& p1, Period& P2)
 {
	 if (!IsOverLapPeriod(p1, P2))
	 {
		 return 0;
	 }
	 short OverLabCount = 0;
	 while (!IsDate1EqualDate2(P2.start, p1.end))
	 {
		 OverLabCount++;
		 increaseDayOnDate(P2.start.Year, P2.start.Month, P2.start.Day);
	 }
	 return OverLabCount;
 }
 bool IsThisValidDate(Date& d1)
 {
	 short numberOfDaysOnMonth = numberOfDaysOnTheMonth(d1.Month, d1.Year);

	 return 	 (d1.Day <= numberOfDaysOnMonth && d1.Day > 0 && d1.Year > 0 && d1.Month > 0 && d1.Month <= 12)

		 ;
 }
 Date EnvertStringTODateStructure(string s1, Date& d1)
 {
	 vector<string>date;
	 date = splitString(s1, "/");
	 d1.Day = stoi(date.at(0));
	 d1.Month = stoi(date.at(1));
	 d1.Year = stoi(date.at(2));
	 return d1;
 }
 void printDateStructure(Date d1)
 {
	 cout << "\nDay : " << d1.Day << "\n Month : " << d1.Month << "\nYear : " << d1.Year << endl;
 }
 string EnvertDateToString(Date& d1)
 {
	 return to_string(d1.Day) + "/" + to_string(d1.Month) + "/" + to_string(d1.Year);
 }
 string ReadDateString()
 {
	 string date;
	 cout << "please enter the date d/mm/yyyy\n";
	 getline(cin >> ws, date);
	 return date;
 }
 string FormatDate(Date& d1, string DateFormat = "dd/mm/yyyy")
 {
	 string FormatDate = "";
	 FormatDate = replaceWordOnSentence(DateFormat, "dd", "/", to_string(d1.Day));
	 FormatDate = replaceWordOnSentence(FormatDate, "mm", "/", to_string(d1.Month));
	 FormatDate = replaceWordOnSentence(FormatDate, "yyyy", "/", to_string(d1.Year));
	 return FormatDate;

 }
