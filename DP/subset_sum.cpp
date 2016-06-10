// http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem


#include <iostream>
#include <vector>

using namespace std;

void
subset_sum()
{
    const std::vector<std::uint64_t> vec = {3, 34, 4, 12, 5, 2};
    const std::uint64_t sum = 9;
    const bool ret = is_subsetsum(vec, sum, vec.size() - 1); 
}

int
main()
{
    subset_sum();
    return 0;
}
