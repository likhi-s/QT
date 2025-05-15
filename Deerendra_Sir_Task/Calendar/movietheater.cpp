#include "movietheater.h"

MovieTheater::MovieTheater()
{
    cout<<"Movie Theater Constructor Called"<<endl;
}

MovieTheater::MovieTheater(int theaterNumber, int seats, string status)
{
    cout<<"Movie Theater Parameterized Constructor Called"<<endl;

    m_theaterNumber = theaterNumber;
    m_seats = seats;
    m_status = status;
}
MovieTheater::~MovieTheater()
{
    cout<<"Movie Theater Destructor Called"<<endl;
}


int MovieTheater::getNumber()
{
    return m_theaterNumber;
}

int MovieTheater::getseats()
{
    return m_seats;
}

string MovieTheater::getStatus()
{
    return m_status;
}
