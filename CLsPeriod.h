#pragma once
#include "ClsDate.h"
class clsPeriod
{

public:
    ClsDate _StartDate;
    ClsDate _EndDate;
   clsPeriod(ClsDate &StartDate, ClsDate &DateTo)
    {
        this->_StartDate = StartDate;
        this->_EndDate = DateTo;

    }
   static  bool IsOverlapPeriods(clsPeriod &Period1, clsPeriod &Period2)
    {

       if (
           ClsDate::CompareDates(Period2._EndDate, Period1._StartDate) == ClsDate::enDateCompare::Before
           ||                                                           
           ClsDate::CompareDates(Period2._StartDate, Period1._EndDate) == ClsDate::enDateCompare::After
           )
           return false;
       else
           return true;
   }
   bool IsMyPeriodOverlapWithThisPeriods(clsPeriod &period)
   {
       return IsOverlapPeriods(*this, period);
   }
   static bool IsThisDateInThisPeriod(ClsDate& date, clsPeriod& period)
   {
       return !(ClsDate::CompareDates(date, period._StartDate) == Before || ClsDate::CompareDates(date, period._EndDate) == After);
   }
   bool IsThisDateInPeriod(ClsDate &date)
   {
      return  IsThisDateInThisPeriod(date, *this);
   }
   static short PeriodLength(clsPeriod &period)
   {
      return ClsDate::DiffBetweenTwoDates(period._StartDate, period._EndDate,true);
   }
   short PeriodLength()
   {
       PeriodLength(*this);
   }
   static void increaseDayOnDate(ClsDate &p1)
   {

       if (p1.Month == 12 && IsThatLastDayOnMonth(p1.Day, p1.Month, p1.Year))
       {
          p1. Year++;
          p1. Month = 1;
          p1. Day = 1;
       }
       else if (p1.Day == numberOfDaysOnTheMonth(p1.Month,p1.Year))
       {
           p1.Day = 1;
           p1.Month++;
       }
       else {
           p1.Day++;
       }

   }
   static  short countOverLabDays(clsPeriod p1, clsPeriod P2)
   {
       if (!clsPeriod::IsOverlapPeriods(p1, P2))
       {
           return 0;
       }
       short OverLabCount = 0;
       while (!ClsDate::IsDate1EqualDate2(P2._StartDate, p1._EndDate))
       {
           OverLabCount++;
          increaseDayOnDate(P2._StartDate);
       }
       return OverLabCount;
   }
   void Print()
    {
        cout << "Period Start: ";
        _StartDate.Print();


        cout << "Period End: ";
        _EndDate.Print();


    }

};
