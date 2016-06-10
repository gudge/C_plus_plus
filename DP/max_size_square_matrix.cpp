// http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void 
foo()
{
    const std::vector<std::vector<std::uint64_t> > vec = 
        {
            {0, 1, 1, 0, 1}, 
            {1, 1, 0, 1, 0}, 
            {0, 1, 1, 1, 0},
            {1, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0}
        };
    
    if (vec.empty())
    {
        return;
    }
    if (vec.size() == 1)
    {
        return;
    }
    if (vec[0].size() == 1)
    {
        return;
    }

    std::vector<std::vector<std::uint64_t> > val; 
    val.reserve(vec.size());
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        val.push_back(std::vector<std::uint64_t>()); 
    }

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        val[i].reserve(vec[i].size());
    }
    val[0] = vec[0];
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        val[i].push_back(vec[i][0]);
    }

    for (std::size_t i = 1; i < vec.size(); ++i)
    {
        for (std::size_t j = 1; j < vec[i].size(); ++j)
        {
            if (vec[i][j] == 1)
            {
                const auto vec2 = { vec[i-1][j-1], vec[i-1][j], vec[i][j-1] } ;
                const auto min = std::min_element(std::begin(vec2), std::end(vec2));
                val[i].push_back(*min + 1);
                if (i == vec.size() - 2 && j == vec[i].size() - 2)
                {
                    std::cout << *min << std::endl;
                }
            }
            else
            {
                val[i].push_back(0);
            }
        }
    }

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        for (std::size_t j = 0; j < vec[i].size() - 1; ++j)
        {
            std::cout << val[i][j] << " ";
        }
        std::cout << val[i][vec[0].size()-1];
        std::cout << std::endl;
    }
}

int
main()
{
    foo();
    return 0;
}
