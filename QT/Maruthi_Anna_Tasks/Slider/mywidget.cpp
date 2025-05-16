#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    cout<<"MyWidget Constructor Called"<<endl;
    setUpUI();
}

MyWidget::~MyWidget()
{
    cout<<"MyWidget Destructor Called"<<endl;

}

void MyWidget::setUpUI()
{

    QSlider *slider = new QSlider(Qt::Horizontal ,this);
    slider->setGeometry(250,80,300,150);
    slider->setRange(0,50);

    connect(slider,&QSlider::sliderMoved,this,&MyWidget::sliderValue);
    m_label = new QLabel(this);
    m_label->setGeometry(280,150,400,300);

}

void MyWidget::sliderValue(int value)
{

    m_label->setText(QString("The current Slider Value is : %1").arg(value));

}
