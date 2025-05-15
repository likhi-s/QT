#ifndef YEAR_H
#define YEAR_H
#include "month.h"
#include <iostream>
#include <vector>
using namespace std;
class Year
{
public:
    Year();
    Year(int year);
    ~Year();
    int getYear();
private:
    int m_year;
    vector<Month>monthList;
};

#endif // YEAR_H
