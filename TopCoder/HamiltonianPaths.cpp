//  HamiltonianPaths
//      Problem: https://community.topcoder.com/stat?c=problem_statement&pm=14250
//      Answer:  https://community.topcoder.com/stat?c=problem_solution&cr=22692969&rd=16842&pm=14250


#include <stdint.h>
#include <iostream>
#include <chrono>

using myint = std::int32_t; 
using hrc = std::chrono::high_resolution_clock;
using clock_type = std::chrono::time_point<hrc>;

std::int32_t countPaths(myint k, const myint a[], myint b[], myint n);
void call1();

myint
countPaths(myint, const myint a[], const myint b[], myint n)
{
    return 0;
}

void 
call1()
{

    const myint a[] = {0, 1};
    const myint b[] = {1, 2};

    const clock_type start = hrc::now();
    const myint count1 = countPaths(3, a, b, 2);   
    const clock_type end = hrc::now();
    const std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << count1 << " : " << elapsed_seconds.count() << '\n';
}

int
main()
{
    call1();
    return 0;
}
