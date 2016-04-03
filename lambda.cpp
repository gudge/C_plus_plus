#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>

void foo()
{
    const std::size_t M = 10;
    std::vector<std::int32_t> vec;
    vec.reserve(M);
    for (std::size_t i = 0; i < M; ++i)
    {
        vec.push_back(i);    
    }
    const auto result = std::find_if(vec.begin(), vec.end(), [](int val) { return 0 < val && val < 5; });
    if (result != vec.end())
    {
        std::cout << "Found" << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }

    using filterContainer = std::vector<std::function<bool(std::int32_t)>>;
    filterContainer filter;
    int x;
    auto c1 = [x](int y) { return x * y > 55; };
    
}   


int
main()
{
    foo();
    return 0;
}
