#pragma once
#pragma warning(disable:4996)
#include <ctime> 
#include <vector>
#include <string>
#include "ClsString.h"
#include "MyDate.h"
#include <chrono>
using namespace std;
class ClsDate
{
private:
	short  _day=1;
	short _month=2;
	short _Year=2002;
public:

	ClsDate()
	{
			time_t t = time(0);
			tm* now = localtime(&t);
			_Year = now->tm_year + 1900;
			_month = now->tm_mon + 1;
			_day = now->tm_mday;
	}
	ClsDate(string date)
	{
		vector<string>VecDate;
		VecDate = ClsString::split(date, "/");
		_day = stoi(VecDate.at(0));
		_month = stoi(VecDate.at(1));
		_Year =stoi( VecDate.at(2));

	}
	ClsDate(short days, short year)
	{
		ClsDate date1 = DateByDaysAndTheYear(days, year);
		_day = date1._day;
		_month = date1._month;
		_Year = date1._Year;
	}
	ClsDate(short day, short month, short year)
	{
		_day = day;
		_month = month;
		_Year = year;
	}
	static Time getCurrentTime() {
		// الحصول على نقطة البداية (الوقت الحالي)
		auto currentTimePoint = std::chrono::system_clock::now();

		// تحويل الوقت الحالي إلى تاريخ ووقت
		std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);

		// استخدام struct لتخزين معلومات الوقت
		struct tm* timeInfo = localtime(&currentTime);
		Time result;
		result.hours = timeInfo->tm_hour;
		result.minutes = timeInfo->tm_min;
		result.seconds = timeInfo->tm_sec;

		return result;
	}
	void SetDay(short day)
	{
		_day = day;
    }
	short GetDay()
	{
		return _day;
	}
	void SetMonth(short Month)
	{
		_month = Month;
	}
	short GetMonth()
	{
		return _month;
	}
	void SetYear(short year)
	{
		_Year = year;
	}
	short GetYear()
	{
		return _Year;
	}
	_declspec(property(get = GetMonth  , put=  SetMonth))short Month;
	_declspec(property(get =GetDay     , put = SetDay ))short Day;
	_declspec(property(get = GetYear   ,put =  SetYear ))short Year;
	ClsDate DateByDaysAndTheYear(short days, short year)
	{
		ClsDate date;
		short month = 0;
		for (short i = 1; i <= days; i++)
		{
			if (days > numberOfDaysOnTheMonth(i, year))
			{
				month++;
				days -= numberOfDaysOnTheMonth(i, year);

			}
			else
			{
				date._day = days;
				date._month = month;
				date._Year = year;
					
			}
		}
		return date;
	}
	string Print()
	 {
		 return DateToString();
	 }
	static ClsDate GetSystemDate(ClsDate &date)
	 {
		
		 time_t t = time(0);
		 tm* now = localtime(&t);
		 date._Year = now->tm_year + 1900;
		 date._month = now->tm_mon + 1;
		 date._day = now->tm_mday;
		 return date;
	 }
	static bool IsThisValidDate(ClsDate& d1)
	 {
		 short numberOfDaysOnMonth = numberOfDaysOnTheMonth(d1._month, d1._Year);
		 return(d1._day <= numberOfDaysOnMonth && d1._day > 0 && d1._Year > 0 && d1._month > 0 && d1._month <= 12)
			 ;
	 }
	bool IsValid()
	{
		return IsThisValidDate(*this);
	}
	static bool IsLeapYear(short year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}
	static short GetTheNumberOfDaysOnYear(short year)
	{
		return IsLeapYear(year) ? 366 : 365;
	}
	short GetTheNumberOfDaysOnYear()
	{
		return GetTheNumberOfDaysOnYear(_Year);
	}
	static int GetTheNumberOfHours(short year)
	{
		return GetTheNumberOfDaysOnYear(year) * 24;
	}
	int GetTheNumberOfHours()
	{
		return  GetTheNumberOfHours(_Year);
	}
	static string PrintMonthName(short monthNumber)
	{
		//هنا يدخل رقم الشهر ويوخرج اسم الشهر
		string ArrMonthsName[] = { "jan","feb","Mar","Apr","may","jun","jul","Augst","sep","oct","nov","des" };
		return ArrMonthsName[monthNumber - 1];
	}
	string PrintMonthName()
	{
		return PrintMonthName(_month);
	}
	static string PrintDayNameByDayOrder(short DayNumber)
	{
		//هنا يدخل رقم اليوم في الترقيم الاسبوعي ويوخرج اسم اليوم
		string ArrDay[] = { "sun","mon","tue" ,"wens" ,"thu","fri","sat" };
		return ArrDay[DayNumber];


	}
	static short EquationForGetNumberOfDayOnWeekList(short year, short month, short day)
	{
		//<vif>calendar
		//معادله رياضيه تاتي برقم اليوم في الترقيم الاسبوعي من خلال رقم الشهر والسنه واليوم
		short a, y, m;
		a = (14 - month) / 12;
		y = year - a;
		m = (month + (12 * a)) - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short EquationForGetNumberOfDayOnWeekList()
	{
		return   EquationForGetNumberOfDayOnWeekList(_Year,_month,_day);
	}
	static int GetTheNumberOfMinute(short year)
	{
		return GetTheNumberOfHours(year) * 60;
	}
	int GetTheNumberOfMinute()
	{
		return GetTheNumberOfMinute(_Year);
	}
	static int GetTheNumberOfSecond(short year)
	{
		return  GetTheNumberOfMinute(year) * 60;
	}
	int GetTheNumberOfSecond()
	{
		return GetTheNumberOfSecond(_Year);
	}
	static void PrintYearCalendar(short month, short year)
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
	void PrintYearCalendar()
	{
		return PrintYearCalendar(_month, _Year);
	}
	static bool IsThatLastDayOnMonth(short NumberOfDays, short month, short year)
	{
		return (NumberOfDays == numberOfDaysOnTheMonth(month, year));
	}
	bool IsThatLastDayOnMonth()
	{
		return IsThatLastDayOnMonth(_day, _month, _Year);
	}
	static bool IsThatLastMonthOnYear(short month)
	{
		return (month == 12);
	}
	bool IsThatLastMonthOnYear()
	{
		return  IsThatLastMonthOnYear(_month);
	}
	static short GetHowManyDaysFromDate(short year, short day, short Allmonths)
	{
		short SumOfDaysOnMonth = day;
		for (short month = 1; month < Allmonths; month++)
		{
			SumOfDaysOnMonth += numberOfDaysOnTheMonth(month, year);
		}
		return SumOfDaysOnMonth;
	}
	short GetHowManyDaysFromDate()
	{
		return  GetHowManyDaysFromDate(_Year, _day, _month);
	}
	static bool IsItEndOfWeek(ClsDate &date)
	{
		return EquationForGetNumberOfDayOnWeekList(date._Year, date._month, date._day) == 5;
	}
	bool IsItEndOfWeek()
	{
		return IsItEndOfWeek(*this);
	}
	static bool IsItWeekEnd(ClsDate& date)
	{
		short numOfTheDay = EquationForGetNumberOfDayOnWeekList(date._Year, date._month, date._day);

		return numOfTheDay == 5 || numOfTheDay == 6;
	}
	bool IsItWeekEnd()
	{
		return  IsItWeekEnd(*this);
	}
	static bool IsItBusniessDay(ClsDate& date)
	{

		return !IsItWeekEnd(date);
	}
	bool IsItBusniessDay()
	{
		return  IsItBusniessDay(*this);
	}
	static bool IsDate1EqualDate2(ClsDate& date1, ClsDate& date2)
	{
		return  (date1._Year == date2._Year) ? ((date1._month == date2._month) ? ((date1._day == date2._day) ? true : false) : false)
			: false;
	}
	bool IsDate1EqualDate2(ClsDate &date)
	{
		return IsDate1EqualDate2(*this, date);
	}
	static bool IsDate1BeforeDate2(ClsDate& date1, ClsDate& date2)
	{
		return  (date1._Year < date2._Year) ? true : ((date1._Year == date2._Year) ? (date1._month < date2._month ? true :
			(date1._month == date2._month ? date1._day <= date2._day : false)) : false);
	}
	bool IsDateBeforeThisDate(ClsDate &date)
	{
		return IsDate1BeforeDate2(*this, date);
	}
    static bool IsDate1AfterDate2(ClsDate& date1, ClsDate& date2)
{
	return (!IsDate1BeforeDate2(date1, date2) && (!IsDate1EqualDate2(date1, date2)));
}
    bool IsDate1AfterDate2(ClsDate &date2)
{
	return IsDate1AfterDate2(*this, date2);
}
	static ClsDate GetSystemDate()
	{
		ClsDate date;
		time_t t = time(0);
		tm* now = localtime(&t);
		date._Year = now->tm_year + 1900;
		date._month = now->tm_mon + 1;
		date._day = now->tm_mday;
		return date;
	}
	static void increaseDayOnDate(short& year, short& month, short& day)
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
	void increaseDayOnDate()
	{
		increaseDayOnDate(_Year,_month,_day);

	}
	static int GetAgeByDays( short& year, short& month, short& day)
		// the date is data from user otherwise the system date.
	{
		ClsDate SystemDate= GetSystemDate();
		int sum = 0;
		while (SystemDate._Year < year || (SystemDate._Year == year && SystemDate._month < month) || (SystemDate._Year == year && SystemDate._month == month && SystemDate._day < day)) {
			sum++;
			increaseDayOnDate(SystemDate._Year, SystemDate._month, SystemDate._day);
		}
		return sum;
	}
	int GetAgeByDays()
	{
		return GetAgeByDays(_Year,_month,_day);
	}
	enum enDateCompare
	{
		Before = -1, After = 1, equal = 0
	};
	static enDateCompare CompareDates(ClsDate& date1, ClsDate& date2)
	{

		if (IsDate1BeforeDate2(date1, date2))
		{
			return enDateCompare::Before;
		}
		else if (IsDate1AfterDate2(date1, date2))
		{
			return enDateCompare::After;
		}
		else
			return enDateCompare::equal;
	}
	static ClsDate ReadFullDate(ClsDate &date1)
	{
		;
		date1._day = GetTheDay();
		date1._month = GetTheMonth();
		date1._Year = GetTheYear();
		return date1;
	}
	ClsDate ReadFullDate()
	{
		ReadFullDate(*this);
	}
	static  void SwapDates(ClsDate& date1, ClsDate& date2)
	{
		Date TempDates;
		TempDates.Year = date1._Year;
		TempDates.Day = date1._day;
		TempDates.Month = date1._month;
		date1._Year = date2._Year;
		date1._month = date2._month;
		date1._day = date2._day;
		date2._Year = TempDates.Year;
		date2._month = TempDates.Month;
		date2._day = TempDates.Day;

	}
	void SwapWithThisDate(ClsDate &date1)
	{
		SwapDates(*this, date1);
	}
	static  short DiffBetweenTwoDates(ClsDate& date1, ClsDate& date2, bool IncludeLastDay)
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
			increaseDayOnDate(date1._Year, date1._month, date1._day);
		}

		return (IncludeLastDay) ? ++days * falgSign : days * falgSign;

	}
	short DiffBetweenDateAndThisDate(ClsDate &date1)
	{
		return DiffBetweenTwoDates(*this, date1,true);
	}
	static short CalculateBusniessDay(ClsDate& dateFrom,ClsDate &dateTo)
	{
		short days = 0;
		while (IsDate1BeforeDate2(dateFrom, dateTo))
		{
			if (IsItBusniessDay(dateFrom))
			{
				days++;
			}
			increaseDayOnDate(dateFrom._Year, dateFrom._month, dateFrom._day);
		}
		return days;

	}
	short CalculateBussneussDaysToThisDate(ClsDate &date1)
	{
		return CalculateBusniessDay(*this,date1);
	}
	static short CalculateVacationDays(ClsDate &DateFrom,ClsDate &DateTo)
	{
		short counter = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (!IsItBusniessDay(DateFrom)) {
				counter++;
				increaseDayOnDate(DateFrom._Year, DateFrom._month, DateFrom._day);
			}
		}
	}
	short CalculateVacationDaysToThisDate(ClsDate &DateTo)
	{
		return  CalculateVacationDays(*this, DateTo);
	}
	static string DateToString(ClsDate date)
	 {
		return to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._Year);
	 }
	string DateToString()
	{
		return DateToString(*this);
	}
};

