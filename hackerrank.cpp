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
#include <assert.h>
#include <memory>

using namespace std;

/********************************************************************/

// https://www.hackerrank.com/challenges/matrix-rotation-algo

std::vector<std::uint64_t> get_strings(const std::shared_ptr<std::istream>& infile);
void print(const std::vector<std::vector<std::uint64_t> >& a); 
std::uint64_t get_iteration(const std::uint64_t ROWS, const std::uint64_t pos);

std::vector<std::uint64_t>
get_strings(const std::shared_ptr<std::istream>& infile)
{
    std::string line;

    if (!std::getline(*infile, line))
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
        const std::vector<std::uint64_t>&a2 = a.at(i);
		for (std::uint64_t j = 0; j < a.at(i).size(); ++j)
		{
        	std::cout << a2.at(j);	
			if (j != (a2.size() - 1))
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


std::uint64_t get_iteration(const std::uint64_t ROWS, const std::uint64_t pos)
{
    std::uint64_t iter = 0;
    if (ROWS % 2)
    {
        iter = (pos > (ROWS / 2)) ? ROWS - pos - 1 : pos;
    }
    else
    {
        iter = (pos >= (ROWS / 2)) ? ROWS - pos - 1 : pos;
    } 

    return iter;
}

void matrix_algo()
{
    std::shared_ptr<std::istream> input;

#if 0
    std::string filename("Input3.txt");
    input.reset(new ifstream(filename.c_str()));
#endif
    input.reset(&std::cin, [](...){});

    std::vector<std::uint64_t> value = get_strings(input);
    const std::uint64_t M = value.at(0);
    const std::uint64_t N = value.at(1);
    const std::uint64_t R = value.at(2);
#if 0
    std::cout << "M " << M << " N " << N << " R " << R << std::endl;
#endif
    std::vector<std::vector<std::uint64_t> > a;
    a.reserve(M);

    for (std::uint64_t i = 0; i < M; ++i)
    {
        value = get_strings(input);
		a.push_back(value);
    }

    //print(a);
               
	if (M == 1 || N == 1)
	{
    	print (a);
		return;
	}

    // std::cout << std::endl;
    for (std::uint64_t i = 0; i < M; ++i) 
    {
        const std::vector<std::uint64_t>& a2 = a.at(i);
        for (std::uint64_t j = 0; j < N; ++j)
        {
            const std::uint64_t M2 = get_iteration(M, i);
            const std::uint64_t N2 = get_iteration(N, j);
            const std::uint64_t MIN_M2_N2 = std::min(M2, N2);
#if 0
            std::cout << "I : " << i
                      << " J : " << j
                      << " M : " << M
                      << " N : " << N 
                      << " M2 : " << M2
                      << " N2 : " << N2
                      << " MIN_M2_N2 : " << MIN_M2_N2
                      << std::endl;
#endif
            assert(M > 2 * MIN_M2_N2);
            assert(N > 2 * MIN_M2_N2);
            const std::uint64_t M3 = M - 2 * MIN_M2_N2;
            const std::uint64_t N3 = N - 2 * MIN_M2_N2;
            const std::uint64_t NO_ELEMS = 2 * (M3  - 1 + N3 - 1);
            const std::uint64_t R2 = R % (NO_ELEMS);
#if 0
            std::cout << "I : " << i 
                      << " J : " << j 
                      << " M : " << M
                      << " N : " << N 
                      <<  " MIN_M2_N2 " << MIN_M2_N2 
                      << " M2 : " << M2
                      << " N2 " << N2
                      << " NO_ELEMS : " << NO_ELEMS 
                      << " R2 : " << R2 
                      << std::endl;
#endif
            const std::uint64_t UPPER_ROW = MIN_M2_N2;
            const std::uint64_t LOWER_ROW = M - 1 - MIN_M2_N2;
            const std::uint64_t LEFT_COL  = MIN_M2_N2;
            const std::uint64_t RIGHT_COL = N - 1 - MIN_M2_N2;
            assert (i >= UPPER_ROW && i <= LOWER_ROW);
            assert (j >= LEFT_COL && j <= RIGHT_COL);

#if 0
            std::cout << "I : " << i 
                      << " J : " << j 
                      << " M : " << M
                      << " N : " << N 
                      <<  " MIN_M2_N2 " << MIN_M2_N2 
                      << " M2 : " << M2
                      << " N2 " << N2
                      << " NO_ELEMS : " << NO_ELEMS 
                      << " R2 : " << R2 
                      << " UPPER_ROW : " << UPPER_ROW
                      << " LOWER_ROW : " << LOWER_ROW
                      << " LEFT_COL : " << LEFT_COL
                      << " RIGHT_COL : " << RIGHT_COL
                      << std::endl;
#endif
            std::uint64_t old_pos = 0;
            if (i == UPPER_ROW)
            {
                old_pos = j - LEFT_COL;
            }
            else if (i == LOWER_ROW)
            {
                old_pos = (M3 - 1) + (N3 - 1) + RIGHT_COL - j;
            }
            else if (j == LEFT_COL)
            {
                old_pos = 2 * (M3 - 1) + (N3 - 1) + LOWER_ROW - i;
            }
            else
            {
                old_pos = (M3 - 1) + i - UPPER_ROW;
            }
            
            std::uint64_t new_pos = (old_pos + R2) % NO_ELEMS;

#if 0
            std::cout << "I : " << i 
                      << " J : " << j 
                      << " a[i][j] : " << a2.at(j) 
#if 0
                      << " M : " << M
                      << " N : " << N 
                      <<  " MIN_M2_N2 " << MIN_M2_N2 
                      << " M2 : " << M2
                      << " N2 " << N2
                      << " NO_ELEMS : " << NO_ELEMS 
                      << " R2 : " << R2 
                      << " UPPER_ROW : " << UPPER_ROW
                      << " LOWER_ROW : " << LOWER_ROW
                      << " LEFT_COL : " << LEFT_COL
                      << " RIGHT_COL : " << RIGHT_COL
#endif
                      << " OP : " << old_pos  
                      << " NP : " << new_pos  
                      << std::endl;           
#endif

            std::uint64_t new_i = 0;
            std::uint64_t new_j = 0;

            const std::uint64_t M4 = M3 - 1;
            const std::uint64_t N4 = N3 - 1;

            if (new_pos <= N4)
            {
               new_j = LEFT_COL + new_pos; 
               new_i = UPPER_ROW;
            }
            else if (new_pos <= M4 + N4) 
            {
                new_pos -= N4;
                new_j = RIGHT_COL;
                new_i = UPPER_ROW + new_pos;
            }
            else if (new_pos < (2 * N4 + M4))
            {
                new_pos -= N4 + M4;
                new_j = RIGHT_COL - new_pos;
                new_i = LOWER_ROW;
            }
            else
            {
                new_pos -= 2 * N4 + M4;
                new_j = LEFT_COL;
                new_i = LOWER_ROW - new_pos;
            }
#if 0
            std::cout 
                      << "I : " << i 
                      << " J : " << j 
                      << " a[i][j] : " << a2.at(j) 
                      << " OP : " << old_pos  
                      << " NP : " << new_pos  
                      << " new_i : " << new_i
                      << " new_j : " << new_j
                      << " " << a.at(new_i).at(new_j)
                      << std::endl;           
#endif
            std::cout << a.at(new_i).at(new_j);
    
            if (j != a.at(i).size())
            {
               std::cout << " ";
            }
        }

        if (i != a.size() - 1)
        {
            std::cout << std::endl;
        }
    }
}

void test_sub(const std::uint64_t M)
{
    // test_sub(4);
    // test_sub(5);
    // test_sub(2);
    for (std::uint64_t i = 0 ; i < M; ++i)
    {
        std::uint64_t M2 = 0;
        if (M % 2)
        {
            M2 = (i > (M / 2)) ? M - i - 1 : i;
        }
        else
        {
            M2 = (i >= (M / 2)) ? M - i - 1 : i;
        }
        std::cout << " M : " << M
                  << " I : " << i
                  << " M2 : " << M2
                  << std::endl; 
    }
}

int
main()
{
    matrix_algo();
    return 0;
}
