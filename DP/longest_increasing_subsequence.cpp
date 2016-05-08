// https://www.hackerrank.com/challenges/longest-increasing-subsequent

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <utility>
#include <vector>
#include <map>

using namespace std;

//#define DEBUG 1

using vec_uint32 = std::vector<std::uint32_t>;

bool input_validation(int argc, char** argv);
void longest_increasing_subsequence(const std::string& fname,
	const bool ifstdin = false);
std::shared_ptr<std::istream> get_input(const std::string& fname,
	const bool ifstdin = false);
uint32_t read_value(std::shared_ptr<std::istream> input);
void print_vector(const vec_uint32& v);
void complexity_on2(const vec_uint32& vec);
void complexity_onlogn(const vec_uint32& vec);

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
	  //std::cout << "File not found : " << fname << std::endl;
	  return false;
	}
  }
  else
  {
	//std::cout << "Please provide filename" << std::endl;
	return false;
  }
}

  void 
print_vector(const vec_uint32& v)
{
  if (v.size() == 0)
  {
  	return;
  }
  for (std::size_t i = 0; i < v.size() - 1; ++i)
  {
	std::cout << v[i] << " ";
  }
  std::cout << v[v.size() - 1];
  std::cout << std::endl;
}

  void
longest_increasing_subsequence(const std::string& fname,
	                           const bool ifstdin)
{
  auto input = get_input(fname, ifstdin);
  const auto N = read_value(input);    
#ifdef DEBUG
  std::cout << "N = " << N << std::endl;
#endif
  vec_uint32 A;
  A.reserve(N);
  for (std::size_t i = 0; i < N; ++i)
  {
	A.push_back(read_value(input));
  }
  //A.clear();
  // A = { 15, 27, 14, 38, 26, 55, 46, 65, 85 };
  //A = { 3, 2, 6, 4, 5, 1 };
#ifdef DEBUG
  print_vector(A);
#endif
  complexity_on2(A);
  //complexity_onlogn(A);
}

  void
complexity_on2(const vec_uint32& vec)
{    
  if (vec.size() == 0)
  {
  	return;
  }
  vec_uint32 v;
  v.reserve(vec.size());
  // Algo : v[i] = Max(vec[i] >= vec[k] ? v[k] + 1 : v[k])
//#define DEBUG2 1
  v.push_back(1);  
  for (std::size_t i = 1; i < vec.size(); ++i)
  {
	std::uint32_t max = 1;
	for (std::size_t j = 0; j < i; ++j)    
	{
	  const std::uint32_t y = vec[i] >= vec[j] ? v[j] + 1 : v[j];
	  if (y > max)
	  {
      	max = y;
	  }
	}  	
#ifdef DEBUG2	  
	std::cout << "i " << i << " max = " << max << std::endl;
#endif
	v.push_back(max);
#ifdef DEBUG2	
	for (std::size_t j = 0; j <= i; ++j)    
	{  
	  std::cout << "Done : i " << i << " j " << j << " v[j] " << v[j] << " : ";
	}	
	std::cout << std::endl;
#endif	
  }
  const auto max = std::max_element(v.begin(), v.end());
  std::cout << "Max Count " << *max << std::endl; 
}

  void 
complexity_onlogn(const vec_uint32& vec)
{
  if (vec.size() == 0)
  {
  	return;
  }
  std::map <std::uint32_t, std::map <std::uint32_t, std::size_t> > val;
  std::size_t max = 1;  
//#define DEBUG3 1
  for (std::size_t i = 0; i < vec.size(); ++i)
  { 
	const auto elem = vec[i];
  	auto it = val.lower_bound(elem);  // first element that is greater-or-equal.  		
	if (it == val.begin())
	{
	  val.emplace(elem, std::map< std::uint32_t, 
		  std::size_t>()).first->second.emplace(elem, 1);
	}
	else
	{
	  if (it->first != elem)
	  {
		--it;
		std::map <std::uint32_t, std::size_t>& map2 = it->second;
		auto it2 = map2.lower_bound(elem); 
		assert (it2 != map2.begin()); 
		if (it2->first != elem)
		{
		  --it2;
		  const auto new_value = it2->second + 1;
		  map2.emplace(elem, new_value);  
		  if (new_value > max)
		  {
          	max = new_value;
		  }
		}
	  }
	}
  }
  std::cout << max << std::endl;
}

  int
main(int argc, char **argv)
{
  if (input_validation(argc, argv))
  {
	longest_increasing_subsequence(std::string(argv[1]));
  }
  else
  {
	longest_increasing_subsequence("", true);
  }
  return 0;
}
