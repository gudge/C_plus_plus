#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

/********************************************************************/

// https://www.hackerrank.com/challenges/matrix-rotation-algo


std::vector<std::string> get_strings(const std::string& line, const std::string& delimiter)
{
    std::vector<std::string> sline;

    size_t next = -1;
    size_t current;

    do
    {
        current = next + 1;    
        next = line.find_first_of(delimiter, current);
        sline.push_back(line.substr(current, next - current));
    }
    while (next != std::string::npos); 


    for (const auto& l : line)
    {
        std::cout << l;
    } 

    return std::move(sline);
}

void matrix_algo()
{
    std::ifstream infile("Input1.txt");

    std::string line;
    std::getline(infile, line);
    std::vector<std::string> sline = get_strings(line, " ");

    std::stringstream ss(sline[0]);
    int M;
    ss >> M;
}


/********************************************************************/


int
main()
{
    matrix_algo();
    return 0;
}
