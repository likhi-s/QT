#ifndef ABC_H
#define ABC_H
#include <QWidget>
#include<qtmetamacros.h>

class ABC:public QWidget
{
public:
    ABC();
    ~ABC();
    void paintEvent();

};

#endif // ABC_H
