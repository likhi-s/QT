#ifndef MOVIETHEATER_H
#define MOVIETHEATER_H
#include <iostream>
using namespace std;

class MovieTheater
{
public:

    MovieTheater();
    MovieTheater(int theaterNumber,int seats,string status);
    ~MovieTheater();

    int getNumber();
    int getseats();
    string getStatus();
private:
    int m_theaterNumber;
    int m_seats;
    string  m_status;
};

#endif // MOVIETHEATER_H
