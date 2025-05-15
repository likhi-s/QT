#ifndef MONTH_H
#define MONTH_H
#include "day.h"
#include <iostream>
#include <vector>
using namespace std;

class Month
{
public:
    Month();
    Month(int month);
    ~Month();
    int getMonth();
    string getMonthName();
    int getDaysInMonth(int year);

    bool isLeapYear(int year);
private:
    int m_month;
    string m_monthNames[12] = { "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
};

#endif // MONTH_H
