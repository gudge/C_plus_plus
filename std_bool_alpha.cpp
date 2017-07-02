#include <iostream>
#include <ios>

int
main()
{
    bool x = false;
    std::cout << x << "\n";
    std::cout << std::boolalpha << x << "\n";
    std::cout << x << "\n";
    std::cout << std::noboolalpha << x << "\n";
    std::cout << x << "\n";
    return 0;
}
