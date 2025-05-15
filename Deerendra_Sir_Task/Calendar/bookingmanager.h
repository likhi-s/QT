#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H
#include <iostream>
#include "movietheater.h"
#include <vector>
#include <map>
#include <iterator>
#include "date.h"

using namespace std;
using theaterId = int ;
class BookingManager
{
public:
    BookingManager();
    ~BookingManager();

    void addMovieTheater();
    void displayTheaterlist();
    int getBookedCount( Date& date);

    int getAvailableTheatersCount( Date &date);
    void displayAvailableTheaters(Date date);
    void bookTheater(Date date, int &theaterNumber);


private:
    map<Date, vector<theaterId>>m_bookingList;
    map<theaterId,MovieTheater*>m_movietheaterList;


};

#endif // BOOKINGMANAGER_H











