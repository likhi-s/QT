#include "calendar.h"
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#define LeftArrow 68
#define RightArrow 67
#define Enter 10

Calendar::Calendar()
{
    cout<<"Calendar Constructor Called"<<endl;
}

Calendar::~Calendar()
{
    cout<<"Calendar Destructor Called"<<endl;
}


void Calendar::displayCalendar(Month *month, Year *year)
{
    clearScreen();
    int startDay = getStartDay(month->getMonth(), year->getYear());
    int totalDays = month->getDaysInMonth(year->getYear());
    cout<<endl<<setw(30)<< "  " << month->getMonthName() << " " << year->getYear() << endl<<endl;

    cout <<setw(15)<< "Sunday"<<setw(15)<< "Monday" <<setw(15)<<"Tuesday"<<setw(15)<< "Wednesday" <<setw(15)<<"Thursday" <<setw(15)<<"Friday" <<setw(15)<<"Saturday" <<setw(15)<< endl<<endl;

    for (int i = 0; i < startDay; ++i)
    {
        cout << setw(15) << "          ";
    }

    for (int d = 1; d <= totalDays; ++d)
    {
        Date date(d, month->getMonth(), year->getYear());
        int available = m_bookingManager->getAvailableTheatersCount(date);
        int booked = m_bookingManager->getBookedCount(date);

        if(available == 0)
        {
            cout << setw(15) << "          ";
            if ((d + startDay) % 7 == 0)
            {
                cout << endl;
            }
            continue;
        }
        if (booked > 0)
        {
            cout << setw(14) << d << "/" << booked;
        }
        else
        {
            cout<<setw(15)<<d;
        }
        if ((d + startDay) % 7 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}


void Calendar::displayCurrentDate()
{
    time_t now = time(0);
    tm *ltm =localtime(&now);
    string months[] = {" ","January", "February", "March", "April", "May", "June ","July", "August", "September", "October", "November", "December"};

    cout<<endl<<endl<<"Current Date: "<<ltm->tm_mday<<" "<<months[1+ltm->tm_mon]<<" "<<(1900+ltm->tm_year)<<" "<<endl<<endl;
}

int Calendar::getStartDay(int month, int year)
{
    if (month < 3)
    {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (1 + 13*(month + 1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return (h + 6) % 7;

}

char Calendar::getch()
{
    char buf = 0;
    struct termios old = {};
    if (tcgetattr(0, &old) < 0) perror("tcgetattr()");
    struct termios new_t = old;
    new_t.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(0, TCSANOW, &new_t) < 0) perror("tcsetattr()");
    if (read(0, &buf, 1) < 0) perror("read()");
    tcsetattr(0, TCSANOW, &old);
    return buf;
}




void Calendar::calendarNavigation()
{
    time_t now = time(0);
    tm *ltm =localtime(&now);
    int month = (1+ltm->tm_mon);
    int year = (1900+ltm->tm_year);
    while (true)
    {
        Month m(month);
        Year y(year);
        this->displayCalendar(&m, &y);
        this->displayCurrentDate();
        cout <<endl<<endl<< "Press < for previous month, > for next month, Enter for Booking Menu." <<endl<< endl;

        char ch = getch();
        if (ch == Enter)
        {
            return;
        }
        else if (ch == LeftArrow)
        {
            month--;
            if (month < 1)
            {
                month = 12;
                year--;
            }
        }
        else if (ch == RightArrow)
        {
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }
}

void Calendar::setBookingManager(BookingManager *bookingManager)
{
    m_bookingManager = bookingManager;
}

void Calendar::clearScreen()
{

        cout << "\033[H\033[J" << flush;

}


