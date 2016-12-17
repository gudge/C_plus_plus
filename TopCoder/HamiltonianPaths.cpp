//  HamiltonianPaths
//      Problem: https://community.topcoder.com/stat?c=problem_statement&pm=14250
//      Answer:  https://community.topcoder.com/stat?c=problem_solution&cr=22692969&rd=16842&pm=14250


#include <stdint.h>
#include <iostream>

std::int32_t countPaths(std::int32_t k, const std::int32_t a[], const std::int32_t b[], std::int32_t n);
void call();

std::int32_t
countPaths(std::int32_t k, const std::int32_t a[], const std::int32_t b[], std::int32_t n)
{
    return 0;
}

void 
call()
{
    const std::int32_t a[] = {0, 1};
    const std::int32_t b[] = {1, 2};
    const std::int32_t count1 = countPaths(3, a, b, 2);   
    std::cout << count1 << '\n';
}

int
main()
{
    call();
    return 0;
}
