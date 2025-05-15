#include "b.h"
#include "a.h"
#include <iostream>
using namespace std;
#include <memory>

B::B()
{
    cout<<"B Constructor called"<<endl;
    unique_ptr<A>aptr = make_unique<A>();
}

B::~B()
{
    cout<<"B Destructor called"<<endl;

}

void B::bfun()
{
    cout<<"B fun Called"<<endl;
}
