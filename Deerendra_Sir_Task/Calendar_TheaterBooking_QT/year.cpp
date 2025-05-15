#include "year.h"

Year::Year()
{
    cout<<"Year Constructor Called"<<endl;
}

Year::Year(int year)
{
    cout<<"Year Parameterized Constructor Called"<<endl;

    m_year = year;
}

Year::~Year()
{
    cout<<"Year Destructor Called"<<endl;
}

int Year::getYear()
{
    return m_year;
}
