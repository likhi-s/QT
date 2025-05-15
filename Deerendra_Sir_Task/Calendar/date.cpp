
#include "date.h"
#include <string>

Date::Date()
{
    cout<<"Date Constructor Called"<<endl;
}
Date::Date(int day,int month,int year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

Date::~Date()
{
    //cout<<"Date Destructor Called"<<endl;
}

int Date::getDay()
{
    return m_day;
}

int Date::getMonth()
{
    return m_month;
}

int Date::getYear()
{
    return m_year;
}



ostream& operator<<(ostream& out,  Date& date)
{
    out << date.m_day <<"-"<< date.m_month <<"-"<< date.m_year;
    return out;
}

bool Date:: operator<(const Date& date)const
{
    if (m_year != date.m_year)
    {
        return m_year < date.m_year;
    }
    if (m_month != date.m_month)
    {
        return m_month < date.m_month;
    }
    return m_day < date.m_day;
}

Date Date::getCurrentDate()
{
    time_t now = time(0);
    tm *ltm =localtime(&now);
    return Date(ltm->tm_mday,(1+ltm->tm_mon),(1900+ltm->tm_year));
}


istream& operator>>(istream& in, Date& date)
{
    while(true)
    {
        string input;
        cout << "Enter date (DD-MM-YYYY): ";
        in >> input;

        for (char& ch : input)
        {
            if (ch == '-')
                ch = ' ';
        }

        stringstream ss(input);

        ss >> date.m_day >> date.m_month >> date.m_year;

        bool valid = true;

        if (date.m_day < 1 || date.m_day  > 31)
        {
            cout << "Invalid day. Must be between 1 and 31." << endl;
            valid = false;
        }

        if (date.m_month  < 1 || date.m_month  > 12)
        {
            cout << "Invalid month. Must be between 1 and 12." << endl;
            valid = false;
        }

        if (date.m_year < 2025 || date.m_year > 9999 || to_string(date.m_year).length() != 4)
        {
            cout << "Invalid year. Must be 4 digits and >= 2025." << endl;
            valid = false;
        }

        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        bool isLeap = (date.m_year % 4 == 0 && (date.m_year % 100 != 0 || date.m_year % 400 == 0));
        if (isLeap) daysInMonth[1] = 29;

        if (date.m_month  >= 1 && date.m_month  <= 12 && date.m_day  > daysInMonth[date.m_month - 1])
        {
            cout << "Invalid day for the given month." << endl;
            valid = false;
        }

        time_t now = time(0);
        tm* local = localtime(&now);

        int currDay = local->tm_mday;
        int currMonth = local->tm_mon + 1;
        int currYear = local->tm_year + 1900;

        if (date.m_year < currYear ||(date.m_year == currYear && date.m_month < currMonth) ||(date.m_year == currYear && date.m_month == currMonth && date.m_day  < currDay))
        {
            cout << "Entered date is in the past. Enter today or a future date." << endl;
            valid = false;
        }

        if(valid)
        {
            cout << "Entered Date (DD-MM-YYYY): " << date.getDay() <<"-"<< date.getMonth()<<"-" <<  date.getYear() << endl;

            break;
        }
    }

    return in;
}
