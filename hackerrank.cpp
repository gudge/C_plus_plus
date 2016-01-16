#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

/********************************************************************/

// https://www.hackerrank.com/challenges/matrix-rotation-algo


std::vector<std::uint64_t>
get_strings(std::ifstream& infile)
{
    std::string line;
    if (!std::getline(infile, line))
    {
        return std::move(std::vector<std::uint64_t>());
    }

    const std::string delimiter(" ");
    std::vector<std::string> sline;

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

#if 0
    for (const auto& v : value)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;
#endif

    return std::move(value);
}

void print(const std::vector<std::vector<std::uint64_t> >& a) 
{
	for (std::uint64_t i = 0; i < a.size(); ++i)
	{
		for (std::uint64_t j = 0; j < a.at(i).size(); ++j)
		{
        	std::cout << a.at(i).at(j);	
			if (j != (a.at(i).size() - 1))
			{
            	std::cout << " ";
			}
		}
		if (i != (a.size() - 1))
		{
			std::cout << std::endl;
		}	
	}
}

void matrix_algo()
{
    std::ifstream infile("Input1.txt");

    std::vector<std::uint64_t> value = get_strings(infile);
    const std::uint64_t M = value.at(0);
    const std::uint64_t N = value.at(1);
    const std::uint64_t R = value.at(2);
    std::cout << "M " << M << " N " << N << " R " << R << std::endl;
    std::vector<std::vector<std::uint64_t> > a(M);

    for (std::uint64_t i = 0; i < M; ++i)
    {
        value = get_strings(infile);
		a.at(i) = value;
    }

    print(a);
               
	if (M == 1 || N == 1)
	{
    	print (a);
		return;
	}

	for (std::uint64_t M2 = M, N2 = N, start = 0; 
		 M2 != 1 && M2 != 0 && N2 != 1 && N2 != 0;
		 M2 -= 2, N2 -= 2, start += 1)
	{
		const std::uint64_t R2 = R % (2 * ((M2 - 1) + (N2 - 1)));
#if 0		
    	std::cout << std::endl << "M2 " << M2 << 
		                          " N2 " << N2 << 
								  " R2 " << R2 << 
								  " start " << start;
#endif		
		std::uint64_t prev = a.at(start).at(start);
		std::uint64_t temp;
		for (std::uint64_t i = start + 1; i < M2; ++i) 
		{
		   temp = a.at(i).at(start);       
		   a.at(i).at(start) = prev;
		   prev = temp;
		}
		std::vector<std::uint64_t>& a2 = a.at(start + N2 - 1);
		for (std::uint64_t i = start + 1; i < N2; ++i)
		{
        	temp = a2.at(i);
			a2.at(i) = prev;
			prev = temp;
		}
#if 0		
		std::cout << std::endl << temp << std::endl;
		print(a);
#endif
		const std::uint64_t col = start + N2 - 1;
		for (std::uint64_t i = M2 - 2; i > start; --i)
		{
            temp = a.at(i).at(col);
		    a.at(i).at(col) = prev;
		    prev = temp;
		}
#if 0		
		std::cout << std::endl << temp << std::endl;
		print(a);
#endif		
		std::vector<std::uint64_t>& a3 = a.at(start);
		for (std::uint64_t i = start + M2 - 1; i > start; --i) 
		{
        	temp = a3.at(i);
			a3.at(i) = prev;
			prev = temp;
		}
        a[start][start] = prev;
		//std::cout << std::endl << temp << std::endl;
		print(a);
		// break;
	}
}

int
main()
{
    matrix_algo();
    return 0;
}
