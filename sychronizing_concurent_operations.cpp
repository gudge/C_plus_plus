/* 

1. Waiting for a event
2. Wait for one off event with futures


*/

#include <vector>
#include <thread>
#include <iostream>


class ThreadSynchronization
{
public:
  	void thread1();
	void thread2();
};


void ThreadSynchronization::thread1()
{
	std::cout << "Thread id1 : " << std::this_thread::get_id() << "\n";
}

void ThreadSynchronization::thread2()
{
	std::cout << "Thread id2 : " << std::this_thread::get_id() << "\n";
}

void threads()
{    
    ThreadSynchronization obj;

	std::thread t1(&ThreadSynchronization::thread1, &obj);
	std::thread t2(&ThreadSynchronization::thread2, &obj);

	t1.join();
	t2.join();   
}

int
main()
{
  	threads();

    return 0;
}
