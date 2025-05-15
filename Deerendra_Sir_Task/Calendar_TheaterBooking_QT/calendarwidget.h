#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <ctime>
#include "calendar.h"

class CalendarWidget : public QWidget
{
    Q_OBJECT
public:
    CalendarWidget(QWidget *parent = nullptr);
    ~CalendarWidget();
private:
    int m_currentYear;
    int m_currentMonth;
    int m_currentDay;
    string m_currentDate;

    Month *m_month;
    Calendar *m_calendar;
    BookingManager *m_bookingManager;

    QPushButton *m_monthTitle;
    QPushButton *m_currentDateDisplay;
    QPushButton *m_dayButtons[42];

    void goToNextMonth();
    void goToPreviousMonth();
    void setupUI();
    void refreshCalendar();

    QVector<QPushButton*> m_theaterButtons; // store theater buttons

    void onDayClicked(int day);
    void onTheaterClicked(int theaterId, const QString &date);

};

#endif // CALENDARWIDGET_H
