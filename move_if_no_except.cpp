#include <iostream>
#include <utility>

struct Bad
{
    Bad() {};
    Bad(Bad&&) // may throw 
    {
        std::cout << "Throwing move constructor" << "\n"; 
    }
    Bad(const Bad&) // may throw
    {
        std::cout << "Throwing copy constructor" << "\n";
    }
};

struct Good
{
    Good() {};
    Good(Good&&) noexcept
    {
        std::cout << "Non throwing move constructor" << "\n";
    }
    Good(const Good&) noexcept
    {
        std::cout << "Non throwing copy construtor" << "\n";
    }
};

int
main()
{
    Good g;
    Bad b;
    Good g2 = std::move_if_noexcept(g);
    Bad b2 = std::move_if_noexcept(b);
    return 0;
}
