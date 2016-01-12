#include <iostream>

using namespace std;

class X
{
   public:
      X();
      /* explicit */ X(const X &obj);  // copy constructor
};

X::X()
{
    std::cout << "Normal constructor allocating ptr" << std::endl;
}

X::X(const X &obj)
{
    std::cout << "Copy constructor allocating ptr." << std::endl;
}


// Main function for the program
int main( )
{
   X x1;
   X x2 = x1; // This also calls copy constructor
   return 0;
}
