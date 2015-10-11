#include <iostream>
#include <memory>
using namespace std;

// Unique pointer example
class X {};

void unique_pointer_example()
{
    unique_ptr<X> x  = make_unique<X>();
}

int
main()
{
    unique_pointer_example();
    return 0;
}

