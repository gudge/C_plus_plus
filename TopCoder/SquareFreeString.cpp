// Problem Statement:
//  https://community.topcoder.com/stat?c=problem_statement&pm=14428
// 


#include <iostream>
#include <string>
#include <stdint.h>
#include <map>

class SquareFreeString
{
    public:
        std::string isSquareFree(std::string s);
};

std::string
SquareFreeString::isSquareFree(std::string s)
{
    enum class result { SQUARE_FREE, NOT_SQUARE_FREE};

    const std::map<result, std::string> resultMap = {{ result::SQUARE_FREE, "suqare-free"}, { result::NOT_SQUARE_FREE, "not suqare-free"}};

    if (s.size() == 1)
    {
        return std::move(resultMap.find(result::NOT_SQUARE_FREE)->second);

    }

    // If there are consecutive characters 
    for (std::uint32_t i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == s[i+1]) 
        {
            return std::move(resultMap.find(result::NOT_SQUARE_FREE)->second);
        }
    }

    for (std::uint32_t i = 0; i < s.size() - 1; ++i)
    {
        for (std::uint32_t j = i + 1; j < s.size() - 1; ++j)
        {
            
            if ((s[i] == s[j]) && (s[i+1] == s[i+1]))
            {
                return std::move(resultMap.find(result::NOT_SQUARE_FREE)->second);
            }
        }
    }
    return std::move(resultMap.find(result::SQUARE_FREE)->second);
}

int
main()
{
    SquareFreeString squareFreeString;
    std::cout << squareFreeString.isSquareFree("bobo") << std::endl;
    std::cout << squareFreeString.isSquareFree("apple") << std::endl;
    std::cout << squareFreeString.isSquareFree("pen") << std::endl;
    std::cout << squareFreeString.isSquareFree("aydyamrbnauhftmphyrooyq") << std::endl;
    std::cout << squareFreeString.isSquareFree("qwertyuiopasdfghjklzxcvbnm") << std::endl;
    std::cout << squareFreeString.isSquareFree("xtejpsfqyiplmyzuotbymtkcmuotbymtkcmrufgsyxmnqmc") << std::endl;
    return 0;
}
