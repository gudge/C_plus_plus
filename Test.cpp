#include <iostream>
#include <memory>
#include <vector>
#include <cstddef>
#include <time.h>
#include <stdlib.h>
#include <bitset>
#include <math.h>

using namespace std;

// Some Imp. Links:
// (1) http://www.ccplusplus.com/2014/01/stl-container-element-c.html
// (2) Why cannot make a vector of references:
// http://stackoverflow.com/questions/922360/why-cant-i-make-a-vector-of-references
//


#if 0
// Unique pointer example
class X {};

void unique_pointer_example()
{
    unique_ptr<X> x  = make_unique<X>();

    // Comilation error for the following line
    // Unique pointer copy constructor cannot be invoked.
    // unique_ptr<X> x2 = x;
}

class Y1
{
    private:
        int y;
    public:
        explicit Y1(int);
        void print(void);
        void sety(int y);
};

Y1::Y1(int y) : y(y) {}
void Y1::print(void)
{
    std::cout << "Y = " << y << std::endl;
}
void Y1::sety(int y)
{
    this->y = y;
}

void test_vector()
{
    Y1 y(10);
    //Y1 y2 = y;
    //y.print();
    //y2.print();
    y.sety(20);
    //y.print();
    //y2.print();
    
    std::vector<Y1> vec;
    vec.reserve(1);
    vec.push_back(y);
    vec[0].sety(30);
    y.print();  // 20
    vec[0].print(); // 30s
}

void test_std_string()
{
    const std::string str("Hello");
    std::string str2("Bar");
    std::cout << str2 << std::endl;
    std::cout << str << std::endl;
}

class Y3 
{
    public:
        explicit Y3(void);
        void foo(void) const;
};

Y3::Y3(void) {}

void Y3::foo(void) const {}

void pass_constant_value(const Y3 y)
{
    y.foo();
}

void test_const_class()
{
    const Y3 y;
    y.foo();
    const Y3 y2;
    y2.foo();
    y.foo();

    Y3 y3;
    Y3 y4;
    y3.foo();
    y4 = y3;
    y4.foo();
 
    pass_constant_value(y2);
    pass_constant_value(y4);
}


class Y2
{
    public:
        explicit Y2(void);
        void foo(void);
        ~Y2();
};

void Y2::foo(void)
{
    std::cout << __func__ << " called";
}
Y2::Y2(void)
{
    std::cout << "Construct Y2" << std::endl;
}
Y2::~Y2()
{
    std::cout << "Destruct Y2";
}
void unique_ptr_refrence(std::unique_ptr<Y2>& ptr)
{
    ptr->foo();
}

void unique_ptr_release(Y2 *y)
{
    y->foo();
}

void test_unique_ptr()
{
    std::unique_ptr<Y2> y = std::make_unique<Y2>();
    y->foo();
    unique_ptr_refrence(y);
    if (y)
    {
        std::cout << "Y not null " << __LINE__ << std::endl;
    }
    else
    {
        std::cout << "Y null" << __LINE__ << std::endl;
    }
    y = std::make_unique<Y2> 
}

// Problems

// -------------------------------------------------------
// problem 3.1

void problem_3_1(const std::string& s)
{
    if (s.empty())
        return;
    auto cnt = 0;
    auto l = '(';
    auto r = ')';
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (*it == l)
            ++cnt;
        else if (*it == r)
            --cnt;
        if (cnt < 0)
        {
            std::cout << s << "  position : " << std::distance(s.begin(), it) << std::endl;
            return;
        }
    }
    std::cout << s << " Match" << std::endl;
}

void problem_3_1_handler()
{
    std::vector<std::string> i;
    i.reserve(3);
    i.push_back("((())())()");
    i.push_back(")()(");
    i.push_back("())");
    const std::vector<std::string> c_i = i;
    i.clear();
    for (auto s : c_i)
        problem_3_1(s);   
}

// -------------------------------------------------------
// Problem 3.2
class N
{
    private:
        int x;
        std::shared_ptr<N> n_ptr;
    public:
        explicit N(int, std::shared_ptr<N>);
        void print(void) const;
        std::shared_ptr<N> getN(void) const;
        void setN(std::shared_ptr<N>);
};

N::N(int x, std::shared_ptr<N> n_ptr = nullptr) : x(x), n_ptr(n_ptr) {}
void N::print(void) const
{
    std::cout << this->x << " ";
}

std::shared_ptr<N> N::getN(void) const
{
    return this->n_ptr;
}

void N::setN(std::shared_ptr<N> n_ptr)
{
    this->n_ptr = n_ptr;
}

void problem_3_2()
{
    // srand (time(NULL));
    // const int mod_v = 20;
    auto h = make_shared<N>(1);
    auto n2 = make_shared<N>(2);
    h->setN(n2);
    auto n3 = make_shared<N>(3);
    n2->setN(n3);
    auto n4 = make_shared<N>(4);
    n3->setN(n4);
  
    for (auto n = h; n;n = n->getN())
    {
        n->print();
    }

    auto x1 = h;
    x1->setN(nullptr);
    auto x2 = n2;
    auto x3 = n3;

    std::cout << std::endl << "Printing Reverse" << std::endl;

    while (1)
    {
        x2->setN(x1);
        x1 = x2;
        if (x3->getN())
        {
            x2 = x3;
            x3 = x3->getN();
        }
        else
        {
            x3->setN(x2);
            h = x3;
            break;
        }
    }
 
    for (auto n = h; n;n = n->getN())
    {
        n->print();
    }
}

// -------------------------------------------------------

// problem 3_4
void problem_3_4()
{
    //const int N = pow(2, 16);
    //const int N = pow(2, 10);
    std::bitset<1024> bitArray(0);
    std::cout << sizeof(bitArray); // 8MB
}

// -------------------------------------------------------

// Trie Implementation
// http://stackoverflow.com/questions/7685649/most-efficient-way-to-store-thousand-telephone-numbers

void telephone_numbers_problem()
{
    
}

// -------------------------------------------------------

int
main2()
{
    //unique_pointer_example();
    //test_vector();
    // problem_3_1_handler();
    // test_unique_ptr();
    // test_std_string();
    // test_const_class();
    // problem_3_2();
    //problem_3_4();
    telephone_numbers_problem();
    return 0;
}

int main3()
{
    auto lambda = [](auto x){ return x; };
    std::cout << lambda("Hello generic lambda!\n");
    return 0;
}


int
main2()
{
    int var = 4;
    auto is_above = [&var](int v) {return v > var;}; 
    if (is_above(3))
    {
        std::cout << "ÿes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }

    const auto vals = {1, 2, 3, 4, 5, 6};
    auto count_b = std:::count_if(vals.begin(), vals.end(), is_above);
    std::cout << count_b << std::endl;

    return 0;
}
#endif

class Button
{
public:
    Button(std::function<void>(void)> click);

}

int main()
{
    
    return 0;
}
