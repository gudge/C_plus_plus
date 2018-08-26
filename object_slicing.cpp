#include <iostream>
#include <cstdint>
using namespace std;

class A
{
	public:
		A(int32_t x);  
		void print_val() const;
	private:
		int32_t val;	
};

A::A(int32_t x) : val(x) {}
void A::print_val() const
{
	std::cout << val << "\n";
}

class B : public A
{
	public:
    	B(int32_t x, int32_t y); 
		void print_val2() const;
	private:
        int32_t val2;
};

B::B(int32_t x, int32_t y) : A(x), val2(y) {}

void B::print_val2() const
{
	std::cout << val2 << "\n";
}


int
main()
{
    B b1(10, 20);
    B b2(30, 40);
	A& a_ref = b2;
	a_ref = b1;
	a_ref.print_val();
	
	b1.print_val();
	b1.print_val2();

	b2.print_val();
	b2.print_val2();

	return 0;
}
