// https://www.hackerrank.com/challenges/longest-increasing-subsequent

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

#define DEBUG 1

bool input_validation(int argc, char** argv);
void longest_increasing_subsequence(const std::string& fname);
std::shared_ptr<std::istream> get_input(const std::string& fname,
                                        const bool ifstdin = false);
uint32_t read_value(std::shared_ptr<std::istream> input);
void print_input(const std::vector<std::uint32_t>& A);

std::uint32_t
read_value(std::shared_ptr<std::istream> input)
{
    std::string line;
    std::getline(*input, line);
    std::stringstream s(line);
    std::uint32_t x; 
    s >> x;
    return x;
}

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

bool
input_validation(int argc, char** argv)
{
    if (2 == argc)
    {
        struct stat buffer;   
        const std::string fname(argv[1]);
        if (stat (fname.c_str(), &buffer) == 0) 
        {
            return true;
        }
        else
        {
            std::cout << "File not found : " << fname << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Please provide filename" << std::endl;
        return false;
    }
}

void 
print_input(const std::vector<std::uint32_t>& A)
{
    for (std::size_t i = 0; i < A.size() - 1; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << A[A.size() - 1];
    std::cout << std::endl;
}

void
longest_increasing_subsequence(const std::string& fname)
{
    auto input = get_input(fname);
    const auto N = read_value(input);    
#ifdef DEBUG
    std::cout << "N = " << N << std::endl;
#endif
    std::vector<std::uint32_t> A;
    A.reserve(N);
    for (std::uint32_t i = 0; i < N; ++i)
    {
        A.push_back(read_value(input));
    }
#ifdef DEBUG
    print_input(A);
#endif
}


int
main(int argc, char **argv)
{
    if (input_validation(argc, argv))
    {
        longest_increasing_subsequence(std::string(argv[1]));
    }
    return 0;
}
