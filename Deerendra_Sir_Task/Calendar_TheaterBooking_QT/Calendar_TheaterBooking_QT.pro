QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookingmanager.cpp \
    calendar.cpp \
    date.cpp \
    day.cpp \
    main.cpp \
    calendarwidget.cpp \
    month.cpp \
    movietheater.cpp \
    year.cpp

HEADERS += \
    bookingmanager.h \
    calendar.h \
    calendarwidget.h \
    date.h \
    day.h \
    month.h \
    movietheater.h \
    year.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
