// https://community.topcoder.com/stat?c=problem_statement&pm=14324
// https://community.topcoder.com/stat?c=problem_solution&cr=23301803&rd=16748&pm=14324
// Categories:  Graph Theory, Greedy 

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

using vec_int = std::vector<std::int32_t>;
using pair_int = std::pair<std::int32_t, std::int32_t>;
using vec_pair = std::vector<pair_int>;

class TriangleEasy
{
    public:
       std::int32_t find(std::int32_t n, const vec_int& x, const vec_int& y); 
};

std::int32_t 
TriangleEasy::find(std::int32_t n, const vec_int& x, const vec_int& y) 
{
    const std::uint32_t edgesCount = x.size();

    if (edgesCount == 0)
    {
        return 3;
    }

    vec_pair vecPair;
    vecPair.reserve(edgesCount);

    for (std::size_t i = 0 ; i < edgesCount; ++i)
    {
        x[i] < y[i] ? vecPair.emplace_back(x[i], y[i]) : vecPair.emplace_back(y[i], x[i]);
    }

    auto sort_vec_pair = [] (const pair_int& v1, const pair_int& v2) 
    {
      if (v1.first < v2.first)
      {
        return true;
      }

      if (v1.first == v2.first)
      {
        if (v1.second < v2.second)
        {
          return true;
        }
      }

      return false;
    };

    std::sort(vecPair.begin(), vecPair.end(), sort_vec_pair);
    std::sort(vecPair.begin(), vecPair.end(), sort_vec_pair);

    for (const auto & 

    n = n;
}

int
main()
{
    TriangleEasy triangleEasy;
    
#if 0
    std::int32_t x[] = {};
    std::int32_t y[] = {};
#endif

#if 0
    {
        const vec_int x = {};
        const vec_int y = {};
        std::cout << triangleEasy.find(3, x, y) << '\n';
    }

    {
        const vec_int x = {0,2,1,2};
        const vec_int y = {3,0,2,3};
        std::cout << triangleEasy.find(4, x, y) << '\n';
    }

    {
        const vec_int x = {0,0,2};
        const vec_int y = {3,1,4};
        std::cout << triangleEasy.find(6, x, y) << '\n';
    }
    
    {
        const vec_int x = {0,2};
        const vec_int y = {1,3};
        std::cout << triangleEasy.find(4, x, y) << '\n';
    }
#endif

    {
        const vec_int x = {16,4,15,6,1,0,10,12,7,15,2,4,8,1,10,15,13,10,1,16,3,19,
                           8,7,13,1,15,15,15,5,16,7,5,6,4,18,3,8,6,2,16,8,19,14,17,
                           16,4,6,9,17,4,10,8,12,2,3,18,9,13,17,4,7,10,0,13,11,15,17,
                           11,15,11,19,19,4,10,14,16,6,3,17,1,4,14,9,7,18,10,11,5,0,5,
                           9,9,7,16,12,4,10,17,3};
        const vec_int y = {17,18,6,16,18,6,11,2,15,10,1,15,17,8,5,9,7,0,0,4,16,1,9,0,9,
                           5,17,14,1,12,14,11,9,18,0,12,11,3,19,14,7,6,3,19,0,1,19,5,11,
                           19,2,13,12,0,6,2,14,16,14,18,5,5,19,3,6,14,12,5,17,3,1,12,7,11,
                           8,8,10,11,13,2,13,13,0,18,2,7,2,12,14,9,3,19,2,8,12,13,8,18,13,18};
        std::cout << triangleEasy.find(20, x, y) << '\n';
    }


    return 0;
}
