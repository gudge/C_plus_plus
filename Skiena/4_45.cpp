#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <functional>

using vec_uint32 = std::vector<uint32_t>;

int
main()
{
    const std::vector<vec_uint32 > vec = {{1, 4, 5}, {4, 9, 10}, {5, 6, 15}}; 
    vec_uint32 iter;
    iter.reserve(vec.size());
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        iter.push_back(0);
    }

    std::priority_queue<vec_uint32, std::vector<vec_uint32>, [] > pq; 
    return 0;
}


