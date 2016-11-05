#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>
#include <functional>

using vec_uint32 = std::vector<uint32_t>;

struct pairs
{
    public:
        int pos;
        int index;
        explicit pairs(int pos1,
                       int index1);
};

pairs::pairs(int pos1,
             int index1) 
             : pos(pos1), index(index1) {}


using vec_pairs = std::vector<struct pairs>;

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

    std::priority_queue<struct pairs, vec_pairs,  > pq; 
    return 0;
}


