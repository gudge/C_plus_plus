//  Problem Statement:
//  https://community.topcoder.com/stat?c=problem_statement&pm=14460&rd=16848&rm=&cr=23177873
//  https://community.topcoder.com/stat?c=problem_statement&pm=14460

// Solution:
//  https://community.topcoder.com/stat?c=problem_solution&cr=23177873&rd=16848&pm=14460


#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;


void call();
int maxLength(std::string s);

int 
maxLength(std::string s)
{
    std::int32_t count = 1; 
    std::int32_t maxCount = 1;

    for (std::uint32_t i = 1; i < s.size(); ++i) 
    {
        if (s[i-1] == s[i])
        {
            if (count > maxCount)
            {
                maxCount = count;
            }
            count = 1;
        }
        else
        {
            ++count;
        }
    }

    if (count > maxCount)
    {
        maxCount = count;
    }

    std::cout << s << " : " << maxCount << std::endl;
    return maxCount;
}

void
call()
{
    if (3 != maxLength("111101111"))
    {
        std::abort();
    }
    if (7 != maxLength("1010101"))
    {
        std::abort();
    }
    if (16 != maxLength("01100101000010101010110101010101010100101010"))
    {
        std::abort();
    }
}

int
main()
{
    call();
    return 0;
}
