#include <iostream>
#include <vector>
#include <cstdlib>

class X
{
    public:
        explicit X();
        explicit X(const X& x);
        explicit X(std::int32_t x);
        void f();
        void f1() const;
        X & operator=(const X& rhs);
        ~X();
    private:
         std::int32_t x;

};


X::X()
{
    std::cout << "Constructor" << std::endl;
}

X::~X()
{
    //std::cout << "Destructor" << std::endl;
}

X::X(const X& x)
{
    std::cout << "Copy constructor" << std::endl;
    x.f1();
}


X::X(std::int32_t x) : x(x)
{
    std::cout << "Constructor with one argument" << std::endl;
}

void X::f()
{
}

void X::f1() const
{
}

X & X::operator=(const X& rhs)
{
    std::cout << "Assignment Operation" << std::endl;
    if (this == &rhs)
        return *this;
    return *this;
}


class X2
{
    public:
        explicit X2(std::int32_t x);
    private : 
        std::int32_t x;
};

X2::X2(std::int32_t x) : x(x)
{
    std::cout << "Single argument constructor" << std::endl;
}

void foo()
{
    constexpr std::int32_t N = 3;
    constexpr std::int32_t M = 10;
#if 0
    X x;
    std::vector<X> vec;
    vec.reserve(N);
    for (int32_t i = 0; i < N; ++i)
    {
        vec.push_back(x);            
    }
    std::cout << "Ëmplace" << std::endl;
    std::vector<X> vec2;
    vec2.reserve(N);
    for (int32_t i = 0; i < N; ++i)
    {
        vec2.emplace_back(x);            
    }
#endif    

#if 0
    X x(10);
    std::vector<X> vec3;
    vec3.reserve(N);
    std::cout << "Push Back" << std::endl;
    for (std::int32_t i = 0; i < M; ++i)
    {
        std::cout << std::endl;
        vec3.push_back(x);
        std::cout << std::endl;
    }
    std::cout << "Push Back done" << std::endl;
    std::vector<X> vec4;
    vec4.reserve(N);
    std::cout << "Emplace" << std::endl;
    for (std::int32_t i = 0; i < M; ++i)
    {
        std::cout << std::endl;
        vec4.emplace_back(i);
        std::cout << std::endl;
    }
    std::cout << "Emplace done" << std::endl;
    std::vector<X> vec5;
    vec5.reserve(N);
    for (std::int32_t i = 0; i < M; ++i)
    {
//        vec5.emplace_back(x);
    }
#endif

#if 0
    std::cout << "XXXXXXXXXXX"  << std::endl;

    X *x2 = new X(3);
    free(x2);

    X *x3 = new X[3];
    delete[] x3;

    std::cout << "XXXXXXXXXXX"  << std::endl;
#endif

    X x(10);
    X *x4 = (X *)malloc(sizeof(X) * 4);
    x4[0] = x;
    
    free(x4);
    
}

int
main()
{
    foo();
    return 0;
}
