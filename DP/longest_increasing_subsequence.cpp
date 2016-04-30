// https://www.hackerrank.com/challenges/longest-increasing-subsequent

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

#define DEBUG 1

using vec_uint32 = std::vector<std::uint32_t>;

bool input_validation(int argc, char** argv);
void longest_increasing_subsequence(const std::string& fname);
std::shared_ptr<std::istream> get_input(const std::string& fname,
	const bool ifstdin = false);
uint32_t read_value(std::shared_ptr<std::istream> input);
void print_input(const vec_uint32& A);
void complexity_on2(const vec_uint32& A);

  std::uint32_t
read_value(std::shared_ptr<std::istream> input)
{
  std::string line;
  std::getline(*input, line);
  std::stringstream s(line);
  std::uint32_t x; 
  s >> x;
  return x;
}

  std::shared_ptr<std::istream>
get_input(const std::string& fname, const bool ifstdin)
{
  std::shared_ptr<std::istream> input;
  std::cout.setf(std::ios_base::unitbuf);
  if (ifstdin)
  {
	input.reset(&std::cin, [](...){});
  }
  else
  {
	input.reset(new std::ifstream(fname.c_str()));
  }
  return input;
} 

  bool
input_validation(int argc, char** argv)
{
  if (2 == argc)
  {
	struct stat buffer;   
	const std::string fname(argv[1]);
	if (stat (fname.c_str(), &buffer) == 0) 
	{
	  return true;
	}
	else
	{
	  std::cout << "File not found : " << fname << std::endl;
	  return false;
	}
  }
  else
  {
	std::cout << "Please provide filename" << std::endl;
	return false;
  }
}

  void 
print_input(const vec_uint32& A)
{
  for (std::size_t i = 0; i < A.size() - 1; ++i)
  {
	std::cout << A[i] << " ";
  }
  std::cout << A[A.size() - 1];
  std::cout << std::endl;
}

  void
longest_increasing_subsequence(const std::string& fname)
{
  auto input = get_input(fname);
  const auto N = read_value(input);    
#ifdef DEBUG
  std::cout << "N = " << N << std::endl;
#endif
  vec_uint32 A;
  A.reserve(N);
  for (std::uint32_t i = 0; i < N; ++i)
  {
	A.push_back(read_value(input));
  }
#ifdef DEBUG
  print_input(A);
#endif
  complexity_on2(A);

}

  void
complexity_on2(const vec_uint32& A)
{    
  vec_uint32 v;
  v.reserve(A.size());
  // v[i] = Max(A[i] >= A[k] ? v[k] + 1 : v[k])
  for (std::uint32_t i = 0; i < A.size(); ++i)
  {
	vec_uint32 v2;
	v2.reserve(i);
	for (std::uint32_t j = 0; j < i; ++j)    
	{
	  std::cout << "i = " << i << " j " << j << " A[j] " << A[j] << " A[i] " << A[i] << std::endl;
	  v2[j] = A[i] >= A[j] ? v[j] + 1 : v[j];  
	}  	
	if (i == 0)
	{  
	  v[i] = 1;  
	}	
	else
	{
	  const auto max = std::max_element(v2.begin(), v2.end());
	  v[i] = *max;
	}
	for (std::uint32_t j = 0; j <= i; ++j)    
	{  
	  std::cout << "i " << i << " j " << j << " v[i] " << v[i] << " : ";
	}	
	std::cout << std::endl;
  }
  const auto max = std::max_element(v.begin(), v.end());
  std::cout << *max << std::endl; 
}

  int
main(int argc, char **argv)
{
  if (input_validation(argc, argv))
  {
	longest_increasing_subsequence(std::string(argv[1]));
  }
  return 0;
}
