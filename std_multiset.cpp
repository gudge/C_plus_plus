#include <set>
#include <cstdint>
#include <iostream>

int
main()
{
    std::multiset<std::int32_t> xset;
    xset.insert(1);
    xset.insert(1);

    for (const auto& elem : xset)
    {
        std::cout << elem << "\n";
    }
    return 0;
}
