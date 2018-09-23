#include <iostream>

class NonCopyable
{
	private:
		NonCopyable(const NonCopyable& obj) = delete;  
		auto operator=(const NonCopyable& obj) -> NonCopyable& = delete;  
	public:	
		//NonCopyable(const NonCopyable& obj) = delete;  
		//auto operator=(const NonCopyable& obj) -> NonCopyable& = delete;  
		NonCopyable();
};

NonCopyable::NonCopyable()
{
	std::cout << "Non copyable \n";
}

int
main()
{
	NonCopyable obj;
	NonCopyable obj2 = obj;
	return 0;
}


