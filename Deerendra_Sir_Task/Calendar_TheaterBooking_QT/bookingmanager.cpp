#include "bookingmanager.h"
#include <algorithm>

BookingManager::BookingManager()
{
    cout<<"Booking Manager Constructor called"<<endl;
    this->addMovieTheater();
}

BookingManager::~BookingManager()
{
    cout<<endl<<"Booking Manager Destructor called"<<endl;
}


void BookingManager::addMovieTheater()
{
    for(int i =1;i<=2;i++)
    {
        m_movietheaterList[i] = new MovieTheater(i,i+5,"Available");
    }
}

void BookingManager::displayTheaterlist()
{
    for(auto theater: m_movietheaterList)
    {
        int id = theater.first;
        int seats = theater.second->getseats();
        string status = theater.second->getStatus();

        cout<<"theater number : "<<id<<" ,number of seats: "<<seats<<",Status: "<<status<<endl;
    }
}

int BookingManager::getBookedCount( Date& date)
{
    return m_bookingList[date].size();
}

int BookingManager::getAvailableTheatersCount(Date &date)
{
    vector<theaterId> booked = m_bookingList[date];
    return m_movietheaterList.size() - booked.size();
}

void BookingManager::displayAvailableTheaters(Date date)
{
    int availableCount =this->getAvailableTheatersCount(date);
    if(availableCount ==0)
    {
        cout <<endl<<"No Theaters Available  on " << date << endl;

    }
    else
    {    cout <<endl<<"Available theaters on " << date << endl;
        vector<theaterId> theaterBooked = m_bookingList[date];

        for (auto theater : m_movietheaterList)
        {
            int id = theater.first;

            if(find(theaterBooked.begin(),theaterBooked.end(),id) == theaterBooked.end())
            {
                cout << " Theater  " << id <<" is available"<< endl;
            }
        }
    }
}

void BookingManager::bookTheater(Date date, int &theaterNumber)
{
    vector<theaterId>& theaterBooked = m_bookingList[date];

    for (auto booked : theaterBooked)
    {
        if (booked == theaterNumber)
        {
            cout << "Theater " << theaterNumber << " is already booked on April " << date << endl;
            return;
        }
    }

    theaterBooked.push_back(theaterNumber);
    cout << "Booked Theater: " << theaterNumber << " on  " << date << " successfully"<<endl;
}



