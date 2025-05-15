#include <QApplication>
#include "calendarwidget.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    CalendarWidget calendarwidget ;
    calendarwidget.show();
    return application.exec();
}
