#include <iostream>

class X
{
    public:
        void operator()() const;
};

void X::operator()() const
{
    std::cout << "Operator" << std::endl;
}

int
main()
{
    const X x;
    x();
}
