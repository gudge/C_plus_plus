#include <iostream>
#include <string>
using namespace std;

std::string 
returnstring()
{
    return "abc";
}


void
foo()
{
    const std::string& str = returnstring();
    std::cout << str << std::endl;
}

int
main()
{
    foo();
    return 0;
}
