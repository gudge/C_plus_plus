//https://www.hackerrank.com/challenges/fibonacci-modified


#include <algorithm>
#include <assert.h>
#include <cmath>
#include <ctgmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <utility>
#include <vector>
#include <map>
#include <limits>
#include <unordered_set>

using namespace std;

//#define DEBUG 1

void find_max_values();
bool input_validation(int argc, char** argv);
void blacknwhite(const std::string& fname,
	             const bool ifstdin = false);
std::shared_ptr<std::istream> get_input(const std::string& fname,
	                                    const bool ifstdin = false);
//std::unordered_set<std::uint32_t> read_value(std::shared_ptr<std::istream> input);
void read_value(std::shared_ptr<std::istream> input);

std::pair<std::uint64_t, std::uint64_t>
read_parse_line(const std::string& line);

std::pair<std::uint64_t, std::uint64_t>
read_parse_line(const std::string& line)
{
    const std::string delimiter(" ");
    std::vector<std::string> sline;
    sline.reserve(2);

    std::size_t next = -1;
    std::size_t current;

    do
    {
        current = next + 1;    
        next = line.find_first_of(delimiter, current);
        sline.push_back(line.substr(current, next - current));
    }
    while (next != std::string::npos); 

    std::vector<std::uint64_t> value;
    value.reserve(sline.size());

    for (const auto& s : sline)
    {
        std::stringstream ss(s);
        std::uint64_t x; 
        ss >> x;
        value.push_back(x);
    }

#if 1
    for (const auto& v : value)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;
#endif 
    return std::move(std::make_pair(value[0], value[1]));

}

//std::unordered_set<std::uint32_t> 
void
read_value(std::shared_ptr<std::istream> input)
{
    std::string line;
    std::getline(*input, line);
    const auto it = read_parse_line(line);
}

std::shared_ptr<std::istream>
get_input(const std::string& fname, 
          const bool ifstdin)
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
	        //std::cout << "File not found : " << fname << std::endl;
	        return false;
	    }
    }
    else
    {
	    //std::cout << "Please provide filename" << std::endl;
	    return false;
    }
}

void blacknwhite(const std::string& fname,
	             const bool ifstdin)
{
    auto input = get_input(fname, ifstdin);
    read_value(input);
}

void
find_max_values()
{
    const auto val = 2 * std::pow(10, 5);    
    const auto val2 = std::numeric_limits<std::uint32_t>::max();
    if (val < val2)
    {
        std::cout << "Use std::uint32_t" << std::endl;
    }
    else
    {
        std::cout << "Use std::uint64_t" << std::endl;
    }
    const auto val3 = 4 * std::pow(10, 10);    
    const auto val4 = std::numeric_limits<std::uint32_t>::max();
    if (val3 < val4)
    {
        std::cout << "Use std::uint32_t" << std::endl;
    }
    else
    {
        std::cout << "Use std::uint64_t" << std::endl;
    }
}

int
main(int argc, char **argv)
{
    
    //find_max_values();
    if (input_validation(argc, argv))
    {
        blacknwhite(std::string(argv[1]));
    }
    return 0;
}
