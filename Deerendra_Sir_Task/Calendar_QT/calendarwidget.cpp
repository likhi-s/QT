#include "calendarwidget.h"
#include "calendar.h"
#include <QPushButton>
#include <QString>

CalendarWidget::CalendarWidget(QWidget *parent): QWidget(parent)
{
    cout<<"Calendar Widget Constructor Called"<<endl;
    setFixedSize(1000, 800);
    setWindowTitle("CALENDAR");

    m_month = new Month;
    m_calendar = new Calendar;

    m_currentYear = m_calendar->getCurrentYear();
    m_currentMonth = m_calendar->getCurrentMonth();
    m_currentDay = m_calendar->getCurrentDay();
    m_currentDate = m_calendar->getCurrentDate();

    setupUI();
    refreshCalendar();
}

CalendarWidget::~CalendarWidget()
{
    cout<<"Calendar Widget Destructor Called"<<endl;

    delete m_month;
    delete m_calendar;
}


void CalendarWidget::setupUI()
{

    int startX = 80;
    int startY = 40;


    QPushButton *leftArrow = new QPushButton("<", this);
    leftArrow->setGeometry(250, startY, 40, 30);
    connect(leftArrow, &QPushButton::clicked, this, &CalendarWidget::goToPreviousMonth);


    QPushButton *rightArrow = new QPushButton(">", this);
    rightArrow->setGeometry(490, startY, 40, 30);

    connect(rightArrow, &QPushButton::clicked, this, &CalendarWidget::goToNextMonth);

    m_monthTitle = new QPushButton(this);
    m_monthTitle->setGeometry(300, startY, 180, 30);

    m_monthTitle->setEnabled(false);


    const char *days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    for (int i = 0; i < 7; ++i)
    {

        QPushButton *button = new QPushButton(days[i], this);
        button->setGeometry(startX + i * 90, startY + 40, 85, 30);
        button->setEnabled(false);
    }

    for (int i = 0; i < 42; ++i)
    {
        m_dayButtons[i] = new QPushButton(this);
        m_dayButtons[i]->setGeometry(startX + (i % 7) * 90, startY + 80 + (i / 7) * 40, 85, 30);

    }


    m_currentDateDisplay = new QPushButton(this);
    m_currentDateDisplay->setGeometry(210, 380, 350, 30);

    m_currentDateDisplay->setEnabled(false);

}

void CalendarWidget::refreshCalendar()
{
    const char *monthNames[] ={ "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};

    QString title = QString("%1 %2").arg(monthNames[m_currentMonth - 1]).arg(m_currentYear);
    m_monthTitle->setText(title);

    QString dateStr = QString("Current Date: %1").arg(m_currentDate);
    m_currentDateDisplay->setText(dateStr);


    for (int i = 0; i < 42; ++i)
    {
        m_dayButtons[i]->hide();
    }

    int startDay = m_calendar->getStartDay(m_currentMonth, m_currentYear);
    int totalDays = m_month->getDaysInMonth(m_currentYear);

    for (int d = 1; d <= totalDays; ++d)
    {
        int index = startDay + d - 1;
        QString number = QString ("%1").arg(d);
        m_dayButtons[index]->setText(number);
        m_dayButtons[index]->show();
    }

}

void CalendarWidget::goToPreviousMonth()
{
    m_currentMonth--;
    if (m_currentMonth == 0)
    {
        m_currentMonth = 12;
        m_currentYear--;
    }
    refreshCalendar();
}
void CalendarWidget::goToNextMonth()
{
    m_currentMonth++;
    if (m_currentMonth == 13)
    {
        m_currentMonth = 1;
        m_currentYear++;
    }
    refreshCalendar();
}
