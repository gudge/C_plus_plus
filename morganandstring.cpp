// https://www.hackerrank.com/challenges/morgan-and-a-string

#include <fstream>
#include <iostream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>
#include <string>

void morgan_and_string();
void lexicographic_minimal_string(const std::string& s1,
	                              const std::string& s2); 

using my_pair = std::pair<std::int32_t, std::size_t>;   

my_pair helper(const std::string& s1,
	           const std::string& s2,
			   const std::size_t pos1,
			   const std::size_t pos2);

my_pair helper(const std::string& s1,
	           const std::string& s2,
			   const std::size_t pos1,
			   const std::size_t pos2)
{
	if (pos1 == s1.size())
	{
		return std::move(std::make_pair(2,   
	}
}

void lexicographic_minimal_string(const std::string& s1, 
	                              const std::string& s2) 
{
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::vector<char> o;
	o.reserve(s1.size() + s2.size());

	std::size_t i;
	std::size_t j;                                                                     	

    for (i = 0, j = 0; i < s1.size() && j < s2.size();)
	{
    	if (s1[i] < s2[j])
		{
        	o.push_back(s1[i]);
			++i;
		}
		else if (s2[j] < s1[i])
		{
        	o.push_back(s2[j]);
        	++j;
		}
		else
		{
		    // equal
        	const my_pair val = helper(s1, s2, i, j);
			if (val.first == 1)
			{
			    assert (i + val.second <= s1.size());
				for (std::size_t i1 = i; i1 < i + val.second; ++i1)  
				{
        			o.push_back(s1[i1]);
				}
            	i += val.second;
			}
			else
			{
			    assert (j + val.second <= s2.size());
				for (std::size_t j1 = j; j1 < j + val.second; ++j1)  
				{
        			o.push_back(s2[j1]);
				}
            	j += val.second;
			}
		}
	}

    assert((i == s1.size()) || (j == s2.size()));
	std::string s3(o.begin(), o.end());
	o.clear();
	if (i != s1.size())
	{
    	s3.append(s1.begin() + i, s1.end());
	}
	else if (j != s2.size())
	{
    	s3.append(s2.begin() + j, s2.end());
	}

	std::cout << s3 << std::endl;
	std::cout << std::endl;
}

void morgan_and_string()
{
    std::shared_ptr<std::istream> input;
#if 1
  	std::cout.setf(std::ios_base::unitbuf);
    std::string filename("Input1.txt");
    input.reset(new std::ifstream(filename.c_str()));
#else
    input.reset(&std::cin, [](...){});
#endif	

    std::string line;
    std::getline(*input, line);

	std::stringstream sT(line);
	std::int32_t T;
	sT >> T;
	std::cout << T << std::endl;
	for (std::int32_t i = 0; i < T; ++i)
	{
    	std::string s1;
    	std::string s2;
		std::getline(*input, s1);
		std::getline(*input, s2);
		lexicographic_minimal_string(s1, s2); 
	}
	return;
}

int
main()
{
    morgan_and_string();
	return 0;
}
