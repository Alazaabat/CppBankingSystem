#pragma once
#pragma warning(disable :4996)
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>

#include"clsString.h"
using namespace std;
class clsDate
{




private:
 
    int _day ;
    int _month ;
    int _year ;
    int ReadNumber(string message) {
        cout << "Enter a " << message << " : ";
        int Number;
        cin >> Number;
        cout << "\n";
        return Number;
    }
    static void DrawDays() {
        cout << "  ";
        for (int i = 1;i <= 7;i++) {
            cout << DayName(i - 1) << "  ";
        }
    }



public:
 
    enum enDateCompare
    {
        eBefore = -1, eEqual = 0, eAfter = 1
    };


    int operator-(const clsDate& Date2) {
        return GetDiffBetweenDates(*this, Date2);
    }
    bool operator==(const clsDate& Date2) {
        return IsDate1EqualDate2(*this, Date2);
    }
    bool operator<(const clsDate& Date2) {
          return IsDate1BerforeDate2(*this, Date2);

      }
    bool operator>(const clsDate& Date2) {
          return (!IsDate1BerforeDate2(*this, Date2) && !IsDate1EqualDate2(*this, Date2));

      }
     
     bool operator!=(const clsDate& Date2) {
          return !IsDate1EqualDate2(*this, Date2);;

      }
 


    clsDate() {
        *this = (GetTodayDate());
    }
    clsDate(int Day,int Month,int Year): _month(Month),_year(Year) {
        _day = Day;
    }
    clsDate(string Date) {
        clsDate TmpDate = StringToDate(Date);
        _day = TmpDate.Day;
        _month = TmpDate.Month;
        _year = TmpDate.Year;
    }
    clsDate(short Days, int Year) {
        clsDate TmpDate = DateFromDay(Days, Year);
        _day = TmpDate.Day;
        _month = TmpDate.Month;
        _year = TmpDate.Year;
    }
    void ReadDate() {
        _day = ReadNumber("Day");
        _month = ReadNumber("Month");
        _year = ReadNumber("Year");
    }
    int GetYear() { return _year; }
    int GetMonth() { return  _month; }
    int GetDay() { return _day; }
    void SetYear(int Year) { this->_year = Year; }
    void SetMonth(int Month) { this->_month = Month; }
    void SetDay(int Day) { this->_day = Day; }
    _declspec(property(get = GetYear, put = SetYear))int Year;
    _declspec(property(get = GetMonth, put = SetMonth))int Month;
    _declspec(property(get = GetDay, put = SetDay))int Day;

    void Print() { cout << DatetoString(*this)<<endl;     }

    static bool IsLeap(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
    bool IsLeap() { return IsLeap(_year); }

    static int DaysInYear(int year) {
        return (IsLeap(year)) ? 366 : 365;
    }
    int DaysInYear() { return DaysInYear(_year); }

    static int HoursInYear(int year) {
        return DaysInYear(year) * 24;
    }
    int HoursInYear() { return HoursInYear(_year); }

    static int MinInYear(int year) {
        return HoursInYear(year) * 60;
    }
    int MinInYear() { return MinInYear(_year); }

    static int SecInYear(int year) {
        return MinInYear(year) * 60;
    }
    int SecInYear() { return SecInYear(_year); }

    static int DaysInMonth(int Year, int Month) {
        int NumberofDays[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
        return  (!(Year > 0 && (Month >= 1 && Month <= 12))) ? 0 :
            Month == 2 ? ((IsLeap(Year)) ? 29 : 28) : NumberofDays[Month - 1];

    }
    int DaysInMonth() { return DaysInMonth(_year, _month); }

    static int HoursInMonth(int Year, int Month) {
        return DaysInMonth(Year, Month) * 24;
    }
    int HoursInMonth() { return HoursInMonth(_year, _month); }

    static int MinInMonth(int Year, int Month) {
        return HoursInMonth(Year, Month) * 60;

    }
    int MinInMonth() { return MinInMonth(_year, _month); }

    static int SecInMonth(int Year, int Month) {
        return MinInMonth(Year, Month) * 60;

    }
    int SecInMonth() { return SecInMonth(_year, _month); }

    static short DayOrderInWeek(int Day, int Month, int Year) {
        if (Day > DaysInMonth(Year, Month))
            return -1;
        int a = floor((14 - Month) / 12);
        int y = Year - a;
        int m = Month + 12 * a - 2;
        int  result = ((Day + y + (int)floor(y / 4) - (int)floor(y / 100) + (int)floor(y / 400) + (int)floor((31 * m) / 12)) % 7);
        return result;
    }
    static short DayOrderInWeek(clsDate Date) { return DayOrderInWeek(Date._day, Date._month, Date._year); }
    short DayOrderInWeek() { return DayOrderInWeek(*this); }

    static string DayName(int Day, int Month, int Year) {
        int Order = DayOrderInWeek(Day, Month, Year);
        if (Order == -1)
            return "";
        string  days_of_week[] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        return days_of_week[Order];
    }
    static string DayName(int Order) {
        if (Order == -1)
            return "";
        string  days_of_week[] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        return days_of_week[Order];
    }
    static string DayName(clsDate Date) { return DayName(Date._day, Date._month, Date._year); }
    string DayName() { return DayName(*this); }

    static string GetMonthName(int M) {
        string months[] = {
            "Jan",
            "Feb",
            "Mar",
            "Apr",
            "May",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"
        };
        return months[M - 1];
    }
    static string GetMonthName(clsDate Date) { return GetMonthName(Date._month); }
    string GetMonthName() { return GetMonthName(_month); }

    static void DrawCalendar(int Month, int Year) {
        cout << "\n  ---------------" << GetMonthName(Month) << "----------------\n";
        cout << "\n";
        DrawDays();
        short Number_of_Days = DaysInMonth(Year, Month);
        int First_Day_Order = DayOrderInWeek(1, Month, Year);
        int i;
        cout << "\n";
        cout << "  ";
        for (i = 0;i < First_Day_Order;i++) {
            cout << "     ";
        }

        for (int j = 1; j <= Number_of_Days; j++)
        {
            cout << setw(5) << to_string(j) + "  ";
            if (++i == 7) {
                printf("\n");
                i = 0;
                cout << "  ";
            }
        }
        cout << "\n  ---------------" << "---" << "----------------\n";

    }
    static void DrawCalendar(clsDate Date) { DrawCalendar(Date._month, Date._year); }
    void DrawCalendar() { DrawCalendar(*this); }

    static void YearCalendar(int Year) {
        cout << "----------------------------" << endl;
        cout << "      Year " << Year << " Calendar" << endl;
        cout << "----------------------------" << endl;

        for (int i = 0; i < 12; i++)
        {
            DrawCalendar(i + 1, Year);
        }
    }
    static void YearCalendar(clsDate Date) { YearCalendar(Date._year); }
    void YearCalendar() { YearCalendar(*this); }

    static int NumberOfDaysFromTheBegOfYear(int day, int Month, int Year) {
        int Number_of_days = 0;
        for (int i = 1; i <= Month - 1; i++)
        {
            Number_of_days += DaysInMonth(Year, i);
        }
        return (Number_of_days + day);
    }
    static int NumberOfDaysFromTheBegOfYear(clsDate Date) { return NumberOfDaysFromTheBegOfYear(Date._day, Date._month, Date._year); }
    int NumberOfDaysFromTheBegOfYear() { return NumberOfDaysFromTheBegOfYear(*this); }

    static clsDate DateFromDay(int Day, int Year) {
        clsDate Date;
        Date._year = Year;
        Date._month = 1;
        int remaining = Day;
        while (true)
        {
            Date._day = DaysInMonth(Date._year, Date._month);
            if (Date._day < remaining) {
                remaining -= Date._day;
                Date._month++;
                if (Date._month > 12) {
                    Date._month = 1;
                    Date._year++;


                }
            }

            else {
                Date._day = remaining;
                break;
            }
        }
        return Date;

    }

    static clsDate AddDaysToDate(clsDate Date, int Days) {
        Date._day = NumberOfDaysFromTheBegOfYear(Date._day, Date._month, Date._year);
        return DateFromDay(Date._day + Days, Date._year);

    }
    void AddDaysToDate(int Days) { *this=AddDaysToDate(*this, Days); }

    static string DatetoString(clsDate Date) {
        return  to_string(Date._day) + "/" + to_string(Date._month) + "/" + to_string(Date._year);
    }
    string DatetoString() { return DatetoString(*this); }

    static bool IsDate1BerforeDate2(clsDate Date1, clsDate Date2) {
        return (Date2._year > Date1._year) ? true : ((Date2._year == Date1._year) ? (Date2._month > Date1._month ? true : (Date2._month == Date1._month ? (Date2._day > Date1._day) : false)) : false);
    }
    bool IsDate1BerforeDate2(clsDate Date2) { return IsDate1BerforeDate2(*this, Date2); }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
        return DatetoString(Date1) == DatetoString(Date2);
    }
    bool IsDate1EqualDate2(clsDate Date2) { return IsDate1EqualDate2(*this, Date2); }

    static bool IsLastDayInMonth(clsDate Date) {
        return Date._day == DaysInMonth(Date._year, Date._month);
    }
    bool IsLastDayInMonth() { return IsLastDayInMonth(*this); }

    static bool IsLastMonthInYear(clsDate Date) {
        return Date._month == 12;
    }
    bool IsLastMonthInYear() { return IsLastMonthInYear(*this); }

    static clsDate IncreaseDateByOneDay(clsDate Date) {
        if (IsLastDayInMonth(Date)) {
            if (IsLastMonthInYear(Date)) {
                Date._month = 01;
                Date._day = 01;
                Date._year += 01;

            }
            else {
                Date._month += 01;
                Date._day = 01;

            }


        }
        else {
            Date._day += 01;

        }

        return Date;
    }
    void IncreaseDateByOneDay() { *this = IncreaseDateByOneDay(*this); }

    static void SwapDates(clsDate& Date1, clsDate& Date2) {
        int x;
        x = Date1._day;
        Date1._day = Date2._day;
        Date2._day = x;

        x = Date1._month;
        Date1._month = Date2._month;
        Date2._month = x;

        x = Date1._year;
        Date1._year = Date2._year;
        Date2._year = x;
    }
    void SwapDates(clsDate& Date2) { SwapDates(*this, Date2); }

    static clsDate GetTodayDate() {
        time_t today = time(0);
        tm* time = localtime(&today);
        return clsDate(time->tm_mday, time->tm_mon + 1, time->tm_year + 1900);
         

    }

    static clsDate IncreaseDateByXDays(clsDate Date, int Days) {
        for (int i = 1; i <= Days; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    void IncreaseDateByXDays(int Days) { *this = IncreaseDateByXDays(*this, Days); }

    static clsDate IncreaseDateByOneWeek(clsDate Date) {
        return   IncreaseDateByXDays(Date, 7);
    }
    void IncreaseDateByOneWeek() { *this = IncreaseDateByOneWeek(*this); }

    static clsDate IncreaseDateByXWeek(clsDate Date, int weeks) {
        for (int i = 0; i < weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }
    void IncreaseDateByXWeek(int weeks) { *this = IncreaseDateByXWeek(*this, weeks); }

    static clsDate IncreaseDateByOneMonth(clsDate Date) {
        Date._month++;
        if (Date._month == 13) {
            Date._month = 1;
            Date._year += 1;
        }
        short NumberMax = DaysInMonth(Date._year, Date._month);
        if (Date._day > NumberMax)
            Date._day = NumberMax;
        return Date;
    }
    void IncreaseDateByOneMonth() { *this = IncreaseDateByOneMonth(*this); }

    static clsDate IncreaseDateByXMonth(clsDate Date, int Monthes) {
        for (int i = 0; i < Monthes; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }
    void IncreaseDateByXMonth(int Monthes) { *this = IncreaseDateByXMonth(*this, Monthes); }

    static clsDate IncreaseDateByOneYear(clsDate Date) {
        Date._year++;
        return Date;

    }
    void IncreaseDateByOneYear() { *this = IncreaseDateByOneYear(*this); }

    static clsDate IncreaseDateByXYear(clsDate Date, short years) {
        for (int i = 0; i < years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    void IncreaseDateByXYear(short years) { *this = IncreaseDateByXYear(*this, years); }

    static clsDate IncreaseDateByOneDecade(clsDate Date) {
        Date = IncreaseDateByXYear(Date, 10);
        return Date;
    }
    void IncreaseDateByOneDecade() { *this = IncreaseDateByOneDecade(*this); }

    static clsDate IncreaseByXdecade(clsDate Date, short decades) {
        for (int i = 0; i <= decades; i++)
        {
            Date = IncreaseDateByOneDecade(Date);
        }
        return Date;
    }
    void IncreaseByXdecade(int decades) { *this = IncreaseByXdecade(*this, decades); }

    static clsDate IncreaseDateByOneCentury(clsDate Date) {
        Date._year += 100;
        return Date;
    }
    void IncreaseDateByOneCentury() { *this = IncreaseDateByOneCentury(*this); }

    static clsDate IncreaseDateByOneMillennium(clsDate Date) {
        Date._year += 1000;
        return Date;
    }
    void IncreaseDateByOneMillennium() { *this = IncreaseDateByOneMillennium(*this); }

    static clsDate DecreaseDateByOneDay(clsDate Date) {
        if (Date._day == 1) {
            if (Date._month == 1) {
                Date._month = 12;
                Date._day = 31;
                Date._year--;
            }
            else {
                Date._month--;
                Date._day = DaysInMonth(Date._year, Date._month);
            }



        }
        else {
            Date._day--;
        }
        return Date;
    }
    void DecreaseDateByOneDay() { *this = DecreaseDateByOneDay(*this); }

    static clsDate DecreaseDateByXDays(clsDate Date, short Days) {
        for (int i = 0; i < Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    void DecreaseDateByXDays(short Days) { *this = DecreaseDateByXDays(*this, Days); }

    static clsDate DecreaseDateByOneWeek(clsDate Date) {
        return (DecreaseDateByXDays(Date, 7));
    }
    void DecreaseDateByOneWeek() { *this = DecreaseDateByOneWeek(*this);}

    static clsDate DecreaseDateByXWeeks(clsDate Date, short weeks) {
        for (int i = 0; i < weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }
    void DecreaseDateByXWeeks(short weeks) { *this = DecreaseDateByXWeeks(*this, weeks); }

    static clsDate DecreaseDateByOneMonth(clsDate Date) {
        Date._month--;
        if (Date._month == 0) {
            Date._month = 12;
            Date._year--;
        }
        short max = DaysInMonth(Date._year, Date._month);
        if (Date._day > max) {
            Date._day = max;
        }
        return Date;
    }
    void DecreaseDateByOneMonth() { *this = DecreaseDateByOneMonth(*this); }

    static clsDate DecreaseDateByXMonthes(clsDate Date, short Monthes) {
        for (int i = 0; i < Monthes; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }
    void DecreaseDateByXMonthes(short Monthes) { *this = DecreaseDateByXMonthes(*this, Monthes); }

    static clsDate DecreaseDateByOneYear(clsDate Date) {
        Date._year--;
        return Date;
    }
    void DecreaseDateByOneYear() { *this = DecreaseDateByOneYear(*this); }

    static clsDate DecreaseDateByXYear(clsDate Date, short years) {
        for (int i = 0; i < years; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    void DecreaseDateByXYear(short years) { *this = DecreaseDateByXYear(*this, years); }
    
    static clsDate DecreaseDateByOneDecade(clsDate Date) {
        Date._year -= 10;
        return Date;
    }
    void DecreaseDateByOneDecade() { *this = DecreaseDateByOneDecade(*this); }

    static clsDate DecreaseDateByXdacades(clsDate Date, short decades) {
        for (int i = 0; i < decades; i++)
        {
            Date = DecreaseDateByOneDecade(Date);
        }
        return Date;
    }
    void DecreaseDateByXdacades(short decades) { *this = DecreaseDateByXdacades(*this, decades); }

    static clsDate DecreaseDateByOneCentury(clsDate Date) {
        Date._year -= 100;
        return Date;
    }
    void DecreaseDateByOneCentury() { *this = DecreaseDateByOneCentury(*this); }

    static clsDate DecreaseDateByOneMillennium(clsDate Date) {
        Date._year -= 1000;
        return Date;
    }
    void DecreaseDateByOneMillennium() { *this = DecreaseDateByOneMillennium(*this);}

    static string DateToStringWithNameOfDay(clsDate Date) {
        return  DayName(DayOrderInWeek(Date._day, Date._month, Date._year)) + " , " + DatetoString(Date);
    }
    string DateToStringWithNameOfDay() { return DateToStringWithNameOfDay(*this); }

    static bool IsEndOfWeek(clsDate Date) {
        return (DayName(DayOrderInWeek(Date)) == "Sat");
    }
    bool IsEndOfWeek() { return IsEndOfWeek(*this); }

    static bool IsWeekEnd(clsDate Date) {
        string today = DayName(DayOrderInWeek(Date));
        return   today == "Fri" || today == "Sat";

    }
    bool IsWeekEnd() { return IsWeekEnd(*this); }

    static bool IsBusinessDay(clsDate Date) {
        return !IsWeekEnd(Date);

    }
    bool IsBusinessDay() { return IsBusinessDay  (*this); }

    static short DaysUntilEndOfWeek(clsDate Date) {
        return 6 - DayOrderInWeek(Date);
    }
    short DaysUntilEndOfWeek() { return DaysUntilEndOfWeek(*this); }

    static short DaysUntilEndofMonth(clsDate Date) {
        return  DaysInMonth(Date._year, Date._month) - Date._day;

    }
    short DaysUntilEndofMonth() { return DaysUntilEndofMonth(*this);}

    static short DaysUntilEndofYear(clsDate Date) {
        return  DaysInYear(Date._year) - NumberOfDaysFromTheBegOfYear(Date);

    }
    short DaysUntilEndofYear() {return DaysUntilEndofYear(*this); }

    static short VacationDays(clsDate from, clsDate To) {
        int DaysCount = 0;
        while (!IsDate1EqualDate2(from, To))
        {
            if (IsBusinessDay(from))
                DaysCount++;
            from = IncreaseDateByOneDay(from);
        }
        return DaysCount;

    }
    short VacationDays(clsDate To) { return VacationDays(*this, To); }

    static clsDate DateAfterVacation(clsDate from, short VacDays) {

        while (VacDays != 0)
        {
            if (IsBusinessDay(from))
            {
                VacDays--;
                from = IncreaseDateByOneDay(from);
            }
            else {
                from = IncreaseDateByOneDay(from);
            }
        }
        return from;

    }
    void DateAfterVacation(short VacDays) { *this = DateAfterVacation(*this, VacDays); }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {

        return IsDate1BerforeDate2(Date2, Date1);

    }
    bool IsDate1AfterDate2(clsDate Date2) { return IsDate1AfterDate2(*this, Date2); }

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {
        if (IsDate1AfterDate2(Date1, Date2)) {
            return eAfter;
        }
        else if (IsDate1BerforeDate2(Date1, Date2)) {
            return eBefore;
        }
        return eEqual;
    }
    enDateCompare CompareDates(clsDate Date2) { return CompareDates(*this, Date2); }

    static bool IsValidDate(clsDate  Date) {
        if (Date._month > 12 || Date._month < 0)
            return false;
        if (Date._day > DaysInMonth(Date._year, Date._month) || Date._day <= 0)
            return false;
        if (Date._year <= 0)
            return false;
        return true;
    }
    bool IsValidDate() { return IsValidDate(*this); }
    
    static clsDate StringToDate(string Date) {
        vector<string> vDate;
        vDate = clsString::Split(Date, "/");
        clsDate sDate;
        sDate.Day = stoi(vDate[0]);
        sDate.Month = stoi(vDate[1]);
        sDate.Year = stoi(vDate[2]);
        return sDate;
    }
    
    static string FormateDate(clsDate Date, string format = "dd/mm/yyyy") {

        string TheNewFortmat = "";
        TheNewFortmat = clsString::Replace(format, "dd", to_string(Date._day));
        TheNewFortmat = clsString::Replace(TheNewFortmat, "mm", to_string(Date._month));
        TheNewFortmat = clsString::Replace(TheNewFortmat, "yyyy", to_string(Date._year));
        return TheNewFortmat;

    }
    static int GetDiffBetweenDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
        int diff = 0;
        short isnegative = 1;
        if (IsDate1BerforeDate2(Date1, Date2)) {
            isnegative = -1;
            SwapDates(Date1, Date2);
        }
        while (!IsDate1EqualDate2(Date1, Date2))
        {
            diff++;
            Date2.IncreaseDateByOneDay();

        }
        return IncludeEndDay ? ++diff * isnegative : diff * isnegative;
    }
    
    static string GetTodayFullDateInString() {
        time_t today = time(0);
        tm* time = localtime(&today);
        return DayName(clsDate()) + " - "+ DatetoString(clsDate()) + " - " + to_string(time->tm_hour) + ":" + to_string(time->tm_min) + ":" + to_string(time->tm_sec);
    }

};
class clsPeriod  {
private:
    clsDate _startDate;
    clsDate _endDate;
public:
    void ReadPeriod() {
        _startDate.ReadDate();
        _endDate.ReadDate();
    }
    clsPeriod(const clsDate &Date1,const clsDate &Date2): _startDate(Date1),_endDate(Date2){}
    clsPeriod(int Day, int Month, int Year, int Day2, int Month2, int Year2) {
        clsDate Date1(Day, Month, Year);
        clsDate Date2(Day2, Month2, Year2);
        clsPeriod(Date1, Date2);

    }
    void SetStartDate(const clsDate &StartDate) {
        _startDate = StartDate;
    }
    void SetStartDate(int Day, int Month, int Year) {
        clsDate Date1(Day, Month, Year);
        SetStartDate(Date1);

    }
    void SetEndDate(const clsDate& EndDate) {
        _endDate = EndDate;
    }
    void SetEndDate(int Day, int Month, int Year) {
        clsDate Date1(Day, Month, Year);
        SetEndDate(Date1);
    }



    static bool IsOverLeap(clsPeriod Period1, clsPeriod Period2) {
        if (!clsDate::IsDate1BerforeDate2(Period1._startDate, Period2._startDate)) {
            clsDate::SwapDates(Period1._startDate, Period2._startDate);
            clsDate::SwapDates(Period1._endDate, Period2._endDate);
        }

        if (clsDate::CompareDates(Period1._endDate, Period2._startDate) == clsDate::enDateCompare::eBefore)
            return false;

        return true;
    }
    bool IsOverLeap(clsPeriod Period2) { return IsOverLeap(*this, Period2);}

    static int PeriodLength(clsPeriod Period, bool IncludeEndDay = false) {
        return -1*clsDate::GetDiffBetweenDates(Period._startDate, Period._endDate, IncludeEndDay);
    }
    int PeriodLength(bool IncludeEndDay = false) { return PeriodLength(*this, IncludeEndDay); }

    static bool IsDateInPeriod(clsPeriod Period, clsDate Date) {
        return  !(clsDate::CompareDates(Period._endDate, Date) == clsDate::enDateCompare::eBefore || clsDate::CompareDates(Period._startDate, Date) == clsDate::enDateCompare::eAfter);

    }
    bool IsDateInPeriod(clsDate Date) { return IsDateInPeriod(*this, Date); }

    static int OverLeapCount(clsPeriod Period1, clsPeriod Period2) {
        int Period1Length = PeriodLength(Period1);
        int Period2Length = PeriodLength(Period2);
        int DaysOverleap = 0;
        if (Period1Length > Period2Length) {
            while (clsDate::IsDate1BerforeDate2(Period2._startDate, Period2._endDate))
            {
                if (IsDateInPeriod(Period1, Period2._startDate))
                    DaysOverleap++;
                Period2._startDate = clsDate::IncreaseDateByOneDay(Period2._startDate);
            }

        }
        else {
            while (clsDate::IsDate1BerforeDate2(Period1._startDate, Period1._endDate))
            {
                if (IsDateInPeriod(Period2, Period1._startDate))
                    DaysOverleap++;
                Period1._startDate = clsDate::IncreaseDateByOneDay(Period1._startDate);
            }

        }
        return DaysOverleap;

    }
    int OverLeapCount(clsPeriod Period2) { return OverLeapCount(*this, Period2); }


};

 