#include "day.h"

Day::Day()
{
    cout<<"Day Constructor called"<<endl;
}

Day::Day(int day)
{
    cout<<"Day Parameterized Constructor called"<<endl;
    m_day =day;
}

Day::~Day()
{
    cout<<"Day Constructor called"<<endl;
}

int Day::getDay()
{
    return m_day;
}
