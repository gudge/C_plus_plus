// https://isocpp.org/wiki/faq/exceptions

#include <iostream>
#include <string>
using namespace std;


class Exception2 : public exception
{
	public:
		const char* what() const noexcept;  
};

const char* Exception2::what() const noexcept
{
	return "C++ custom exception";
}

class Exception3
{
	public:
		std::string what() const noexcept;  
};

std::string Exception3::what() const noexcept
{
	return "C++ custom exception: Exception3";
}

class A
{
	public:
		void work(void);
};

void A::work(void)
{
	try
	{
	   throw Exception2();   
	}
    catch(const Exception2& ex)
	{
    	std::cout << "Exception caught " 
		          << ex.what() << "\n";
	}
    catch(const std::exception& ex)
	{
    	std::cout << "Exception caught " 
		          << ex.what() << "\n";
	}

	try
	{
    	throw Exception3();
	}
	catch(const Exception3& ex)
	{
    	std::cout << "Exception caught " 
		          << ex.what() << "\n";
	}
}


void foo()
{
  	A a;
	a.work();
}

int
main()
{
  	foo();
	return 0;
}
