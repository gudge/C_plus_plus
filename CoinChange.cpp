// https://www.hackerrank.com/challenges/coin-change
// 1. n = 3 C = 8.3.1.2  Ans : 3 ===> 1,1,1 1,2 3
// 2. n= 4 C = 1 2 3 Ans : 4
// 3. n = 10 C = 2 5 3 6 Ans : 5
//
// 1 <= c <= 50 1 <= n <= 250 1 <= m <= 50
// Strategy:
// 	 		c ---> sort   
// 	 		c ---> []() { if x < n }
// 		 	
// 	Soln of  ax + by = c
// 			https://math.stackexchange.com/questions/20717/how-to-find-solutions-of-linear-diophantine-ax-by-c
// 			https://math.stackexchange.com/questions/20906/how-to-find-an-integer-solution-for-general-diophantine-equation-ax-by-cz?rq=1
// 	Dynamic Programming:		
// 			http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/DynProg/knapsack2.html
//

#include <algorithm>
#include <assert.h>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using vec64 = std::vector<uint64_t>;

uint64_t getWays(uint64_t n, std::vector<uint64_t>& c);
void coin_change();
void print_vec64(const vec64& vec);
vec64 read_line(std::shared_ptr<std::istream> input);
 
uint64_t 
getWays(uint64_t n, std::vector<uint64_t>& c)
{
    if (n == 0)
    {
	  	if (c.empty())
		{
        	return 0;
		}
        return 1;
    }

    if (c.empty())
    {
        return 0;
    }

    std::sort(c.begin(), c.end());
	c.erase(std::remove_if(c.begin(), c.end(), [n](uint32_t x){ return x > n; }), c.end());
    if (c.empty())
    {
        return 0;
    }

    const std::uint64_t m = c.size(); 	
	std::cout << "n =  " << n << '\n';
	print_vec64(c);

    return 0;
}

int
main()
{
    coin_change();
    return 0;
}  
 
void 
print_vec64(const vec64& vec)
{
    if (vec.empty())
    {
        return;
    }

    std::string str;
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        str += std::to_string(vec[i]);    
        if (i != (vec.size() - 1))
        {
            str += " ";
        }
    }

    std::cout << str << '\n';
}
 
void
coin_change()
{
    std::shared_ptr<std::istream> input;

    //input.reset(&std::cin, [](...){});
    input.reset(new std::ifstream(std::string("Input1.txt")));
    
    std::cout.setf(std::ios_base::unitbuf);

    const vec64 vec = read_line(input);
    const std::uint64_t n = vec[0];
    const std::uint64_t m = vec[1];
    vec64 C = read_line(input);
    assert (C.size() == m);

    std::cout << getWays(n, C) << "\n";
    
    return;
} 

vec64
read_line(std::shared_ptr<std::istream> input)
{
    vec64 vec;
    std::string line;
    std::getline(*input, line);
    std::stringstream is( line );

    uint64_t number;
    while ( is >> number )
    {
        vec.push_back(number);
    }

    //print_vec64(vec);
    return std::move(vec);
} 
