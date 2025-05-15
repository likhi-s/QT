#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <ctime>
#include "calendar.h"

class CalendarWidget : public QWidget
{

public:
    CalendarWidget(QWidget *parent = nullptr);
    ~CalendarWidget();
private:
    int m_currentYear;
    int m_currentMonth;
    int m_currentDay;
    string m_currentDate;

    Calendar* m_calendar;
    Month *m_month;

    QPushButton *m_monthTitle;
    QPushButton *m_currentDateDisplay;
    QPushButton *m_dayButtons[42];

    void goToNextMonth();
    void goToPreviousMonth();
    void setupUI();
    void refreshCalendar();

};

#endif // CALENDARWIDGET_H
