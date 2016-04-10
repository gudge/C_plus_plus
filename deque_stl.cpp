#include <iostream>
#include <string>
#include <memory>
#include <fstream>

void dequeue_stl()
{

    std::shared_ptr<std::istream> input;
#if 1
  	std::cout.setf(std::ios_base::unitbuf);
    std::string filename("Input1.txt");
    input.reset(new std::ifstream(filename.c_str()));
#else
    input.reset(&std::cin, [](...){});
#endif	

}

int
main()
{
    dequeue_stl();
    return 0;
}
