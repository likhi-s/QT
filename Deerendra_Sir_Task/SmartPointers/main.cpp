#include <iostream>
#include "b.h"
#include "a.h"

using namespace std;
#include <memory>

int main()
{
    unique_ptr<B>buniqueptr = make_unique<B>();
    buniqueptr->bfun();
    unique_ptr<A>auniqueptr = make_unique<A>();
    auniqueptr->afun();
    unique_ptr<B>bptr = make_unique<B>();

    buniqueptr = move(bptr);
    buniqueptr->bfun();

    cout << "Hello World!" << endl;
    return 0;
}
