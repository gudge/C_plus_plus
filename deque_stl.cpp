#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

std::shared_ptr<std::istream> get_input(const bool ifstdin = false);
std::int32_t read_integer(std::shared_ptr<std::istream> input);
void dequeue_stl();

std::shared_ptr<std::istream> get_input(const bool ifstdin)
{
    std::shared_ptr<std::istream> input;
    const std::string filename("Input1.txt");
  	std::cout.setf(std::ios_base::unitbuf);
    if (ifstdin)
    {
        input.reset(new std::ifstream(filename.c_str()));
    }
    else
    {
        input.reset(&std::cin, [](...){});
    }
    return input;
}

std::int32_t read_integer(std::shared_ptr<std::istream> input)
{
    std::string line;
    std::getline(*input, line);
	std::stringstream sT(line);
	std::int32_t i;
    sT >> i;
    return i;
}

void dequeue_stl()
{
    std::shared_ptr<std::istream> input = get_input();
    const std::int32_t T = read_integer(input);
    std::cout << T << std::endl;
	for (std::int32_t i = 0; i < T; ++i)
    {

    }
}

int
main()
{
    dequeue_stl();
    return 0;
}
