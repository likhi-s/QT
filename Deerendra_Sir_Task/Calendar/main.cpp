#include <iostream>
#include "calendar.h"
#include "movietheater.h"
#include "bookingmanager.h"
#include "calendar.h"
using namespace std;
enum choice{DisplayTheaterlist = 1,BookTheater,Exit};

//Qwidget,QpushButton,SetGeometry,grayout(booked theaters)

int main()
{
    Calendar calendar;
    BookingManager bookingManager;
    calendar.setBookingManager(&bookingManager);
    calendar.calendarNavigation();

    Date date;
    while(true)
    {

        int choice;
        cout<<endl<<"1.DisplayTheaterlist"<<endl<<"2.BookTheater"<<endl<<"3.Exit"<<endl;
        cout<<endl<<"Enter Your Choice :";
        cin>>choice;
        switch(choice)
        {
        case DisplayTheaterlist:
        {
            bookingManager.displayTheaterlist();
        }
        break;
        case BookTheater:
        {
            cin>>date;
            bookingManager.displayAvailableTheaters(date);
            int availableCount =bookingManager.getAvailableTheatersCount(date);
            if(availableCount !=0)
            {
                int number;
                cout<<endl<<"Enter Theater Number :";
                cin>>number;
                bookingManager.bookTheater(date,number);
            }
            else
            {
                cout <<endl<<"No Theaters Available  on " << date << endl;
            }

            calendar.calendarNavigation();
            break;
        }
        case Exit:
            return 0;

        }
    }


    return 0;
}



