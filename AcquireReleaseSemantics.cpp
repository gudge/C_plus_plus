#include <iostream>
#include <atomic>

int
main()
{
  	std::atomic<int> A;
	A.store(1, std::memory_order_release);
	return 0;
}
