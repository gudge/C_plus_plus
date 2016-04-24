// http://www.learncpp.com/cpp-tutorial/125-the-virtual-table/

// Simple Case

class Base
{
public:
    virtual void function1() {};
    virtual void function2() {};
};
 
class D1: public Base
{
public:
    virtual void function1() {};
};
 
class D2: public Base
{
public:
    virtual void function2() {};
};

class Base
{
   // vptr _vptr;  --->    func1
   //                      func2 
};

class D1 : public Base
{
	// vptr _vptr; --->    d1_func1 
	//                     func2
};	

class D2 : public Base
{
	// vptr _vptr; --->    func1 
	//                     d2_func2
};
