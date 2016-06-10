#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;


void
max_sumarray()
{
    const std::vector<std::int64_t>  vec = {-2, -3, 4, -1, -2, 1, 5, -3};       
    bool all_neg = true;
    for (auto i : vec)
    {
        if (i > 0)
        {
            all_neg = false;
            break;
        }
    }
    if (all_neg)
    {
        const auto max = std::max_element(vec.begin(), vec.end());
        std::cout << *max << std::endl;
    }

    int max = 0;
    int max2 = 0;
    for (auto i : vec)
    {
        if (max2 + i < 0)
        {
          max2 = 0;
        } 
        else
        {
           max2 += i;
        }
        if (max2 > max)
        {
            max = max2;
        }
    }
    std::cout << max << std::endl;
}

int
main()
{
    max_sumarray(); 
    return 0;
}
