#include <iostream>

class Xstring
{
public:
    /**
     * Allocate n bytes for the string
     */
    explicit Xstring(int n);
    void foo();
};

Xstring::Xstring(int n) 
{
    std::cout << "n: " << n << "\n" ;
}

void Xstring::foo() 
{
    std::cout << "X::foo \n";
}

void foo(Xstring x)
{
    x.foo();   
}

int
main()
{
    //Xstring x = 'x';
    foo(2);   
}
