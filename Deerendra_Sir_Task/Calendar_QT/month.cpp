#include "month.h"

Month::Month()
{
    cout<<"Month Constructor Called"<<endl;
}

Month::Month(int month)
{
    cout<<"Month Parameterized Constructor Called"<<endl;

    m_month = month;
}

Month::~Month()
{
    cout<<"Month Destructor Called"<<endl;
}

int Month::getMonth()
{
    return m_month;
}

string Month::getMonthName()
{
    return m_monthNames[m_month-1];
}

int Month::getDaysInMonth(int year)
{
    if(m_month == 2)
    {
        return (isLeapYear(year) ?29 :28);
    }
    else if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}
bool Month:: isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
