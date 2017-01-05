// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4164.pdf


#include <iostream>
#include <utility>
using namespace std;

class X{};

class Y
{
    public:
        void foo(X&& x);
        void foo2(X&& x);
        void foo2(X& x);
        template <typename T>
        void foo3(T &&t)
        {
            foo2(std::forward(t));
        }
};

void
Y::foo(X&& x)
{
    std::cout << "R Value : X&&" << '\n';
}

void
Y::foo2(X&& x)
{
    std::cout << "R Value : X&&  : foo2 " << '\n';
}

void
Y::foo2(X& x)
{
    std::cout << "L Value : X&&  : foo2 " << '\n';
}


void
foo()
{
    Y y;
    X x;
    y.foo(std::move(x));
    y.foo2(X());
    y.foo2(x);
}

int
main()
{
    foo();
    return 0;
}
