//  g++ --std=c++14 -Wall -Wextra -Werror -Wfatal-errors  -Weffc++ -pedantic  -g3 -gdwarf-2 move_semantics.cpp -o move_semantics

/****************************************************************************/
// 1) std::swap
// 2) std::move
// 		Turns a argument into a R-value? How ?
// 3) 
/****************************************************************************/

/****************************************************************************/
// std::move:
// 		std::move doesn't move anything and it is not always cheaper than copying.
// 		Ambiguous nature of the type &&.
//
// 		std::move Does not move anything. At runtime does not do anything. Not generate a signle executable byte.
//
// template<typename T>
// typename remove_reference<T>::type&&
// move(T&& param)
// {
// 		using ReturnType = typename remove_reference<T>::type&&;
// 		return static_cast<ReturnType>(param);
// }
//
// This is confusing:
// http://stackoverflow.com/questions/12011426/how-to-use-move-semantics-with-stdstring-during-function-return
// Asks not to return a R-value reference

/****************************************************************************/
#include <iostream>                 
#include <utility>
#include <vector>
#include <string>

/****************************************************************************/
/****************************************************************************/
// http://www.learncpp.com/cpp-tutorial/911-the-copy-constructor-and-overloading-the-assignment-operator/

class X3
{
	public:
		explicit X3();  
		X3(const X3& x3);
		X3& operator=(const X3& x3);
		void dummy() const;
};

X3::X3()
{
	std::cout << "Default Contructor X3" << std::endl;
}

X3::X3(const X3& x3) 
{
	std::cout << "Copy Contructor X3" << std::endl;
	x3.dummy();
}

X3& X3::operator=(const X3& x3)
{
    if (this == &x3)
	{
    	return *this;
	}

	std::cout << "Assignment operator overloaded X3" << std::endl;  
	x3.dummy();
    return *this;
}

void X3::dummy() const
{
	std::cout << "Dummy X3" << std::endl;  
}

void execute1()
{
	X3 x1;
    X3 x2 = x1;
	x2.dummy();
}

/****************************************************************************/
/****************************************************************************/

// http://thbecker.net/articles/rvalue_references/section_02.html
class Resource{};
class X2 
{
	std::vector<Resource> m_pResource;      
};
// Overload the assignment operator
//X2& X2::operator=(
/****************************************************************************/

void string_move(void);
void object_move(void);

class X
{
	public:
		explicit X(int y); 
		void print();
	private:
		int y;  
};

X::X(int y) : y(y)
{
}

void X::print()
{
	std::cout << "Y = " << y << std::endl;  
}

void object_move(void)
{
	X x(2);
	x.print();
	X x2(3);
	x2.print();
	x2 = std::move(x);
	x.print();
	x2.print();
}

void string_move(void)
{
  	std::string hello("hello");
	std::string world("world");
	std::cout << "hello = " << hello << " world = " << world << std::endl;
	hello = std::move(world);
	std::cout << "hello = " << hello << " world = " << world << std::endl;
}
/****************************************************************************/
/****************************************************************************/
// https://msdn.microsoft.com/en-us/library/dd293665.aspx 

// http://stackoverflow.com/questions/4986673/c11-rvalues-and-move-semantics-confusion-return-statement
/****************************************************************************/

void try_out_r_value_ref()
{
	int&& rref = 2 * 3;
	const int& ref = 3 * 6;
	std::cout << "rref = " << rref << " &rref = " << &rref << " ."<< std::endl;
	int a = 3;
	rref = a;
	rref = 5;
	std::cout << "rref = " << rref << " &rref = " << &rref  << " a = " << a << " ."<< std::endl;
	std::cout << "ref = " << ref << " ." << std::endl;
}

/****************************************************************************/


/****************************************************************************/
// http://www.drdobbs.com/cpp/moving-and-rvalue-references/240157455


void bar2(int&& s)
{
    std::cout << "Bar2 rvalue called " << s << " ." << std::endl;
}

void bar2(int& s)
{
    std::cout << "Bar2 lvalue called " << s << " ." << std::endl;
}

void foo1()
{
    //int&s = 3;

    bar2(3);
    int s = 5;
    bar2(s);
}

/****************************************************************************/

// Universal refernces
// https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers

/****************************************************************************/

int
main()
{
    //string_move();
    //object_move();
	// execute1();
	//msdn_move_constructor_example();
	//try_out_r_value_ref();
    foo1();
	return 0;
}

