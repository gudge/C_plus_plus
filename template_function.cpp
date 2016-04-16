#include <iostream>

template<class T>
T foo();

template<class T>
T foo()
{
    T t;
    return t; 
}

int
main()
{
    int x = foo();
    return 0;
}
