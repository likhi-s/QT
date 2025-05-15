#ifndef DAY_H
#define DAY_H
#include <iostream>
using namespace std;

class Day
{

public:
    Day();
    Day(int day);
    ~Day();
    int getDay();
private:
    int m_day;
};

#endif // DAY_H
