#include "abc.h"
#include <iostream>
using namespace std;

ABC::ABC()
{
    cout<<"ABC Constructor Called"<<endl;
}

ABC::~ABC()
{
    cout<<"ABC Destructor Called"<<endl;

}

void ABC::paintEvent()
{
    cout<<"ABC Paint Event Called"<<endl;
}
