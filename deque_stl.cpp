// https://www.hackerrank.com/challenges/deque-stl

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#define DEBUG 1

std::shared_ptr<std::istream> get_input(const std::string& fname,
                                        const bool ifstdin = false);
std::int32_t read_integer(std::shared_ptr<std::istream> input);
void dequeue_stl(const std::string& fname);
bool input_validation(int argc);

std::shared_ptr<std::istream>
get_input(const std::string& fname, const bool ifstdin)
{
    std::shared_ptr<std::istream> input;
  	std::cout.setf(std::ios_base::unitbuf);
    if (ifstdin)
    {
        input.reset(&std::cin, [](...){});
    }
    else
    {
        input.reset(new std::ifstream(fname.c_str()));
    }
    return input;
}

std::int32_t
read_integer(std::shared_ptr<std::istream> input)
{
    std::string line;
    std::getline(*input, line);
	std::stringstream sT(line);
	std::int32_t i;
    sT >> i;
    return i;
}

void
dequeue_stl(const std::string& fname)
{
    std::shared_ptr<std::istream> input = get_input(fname);
    const std::int32_t T = read_integer(input);
#ifdef DEBUG
    std::cout << T << std::endl;
#endif
	for (std::int32_t i = 0; i < T; ++i)
    {
        const std::int32_t N = read_integer(input);
        const std::int32_t K = read_integer(input);
        const std::int32_t A = read_integer(input);
#ifdef DEBUG
        std::cout << "N = " << N << "K = " << K << "A = " << A << std::endl;
#endif
    }
}

bool
input_validation(int argc)
{
    if (2 == argc)
    {
        return true;
    }
    else
    {
        std::cout << "Please provide filename" << std::endl;
        return false;
    }
}

int
main(int argc, char**argv)
{
    if (input_validation(argc))
    {
        dequeue_stl(std::string(argv[1]));
    }
    return 0;
}
