#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <iostream>
using namespace std;
#include <QWidget>
#include <QSlider>
#include <QLabel>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void setUpUI();
    void sliderValue(int value);

private:
    QLabel *m_label;
};
#endif // MYWIDGET_H
