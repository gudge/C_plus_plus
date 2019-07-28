// https://www.hackerrank.com/challenges/determining-dna-health/problem

// https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm
// Boyer Moore
// KMP String matching algorithm
// Aho–Corasick_algorithm
// Trie
// Persistent segmentation tree
//
// Cormen 32.3 String matching with finite automata
//
// CLRS Solutions: https://walkccc.github.io/CLRS/Chap32/32.3/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <random>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>
#include <limits>

// Problem statement


//###################################################################################
//32.1-2
//Suppose that all characters in the pattern P are different. Show how to accelerate
//NAIVE-STRING-MATCHER to run in time O.n/ on an n-character text T .


#define DEBUG 1
void exercise_32_1_2();

class PatternMatch
{
public:
    PatternMatch(const std::string& text,
    			 const std::string& pattern);
	const std::string& get_text() const;
	const std::string& get_pattern() const;
    bool pattern_unique_match() const;
	bool kmp();
	void compute_partial_match_table();
	const std::vector<size_t>& get_partial_match_table() const;
private:
    std::string m_text;
    std::string m_pattern;
    std::vector<size_t> m_partial_match_table;  
};

class TestHelperClass
{
public:
    explicit TestHelperClass(const PatternMatch& p);
    void pattern_unique_match() const;
	void kmp() const;
	void test_compute_partial_match_failed() const;
private:	
	PatternMatch m_p;	
};

class HelperClass
{
public:
  	HelperClass(); 
    void test_uniqueness(const std::string& str) const;
	std::string get_random_string(const std::size_t len,
		                          bool unique_characters);
	std::size_t get_random_integer();
	std::size_t get_random_integer_less_than(const std::size_t val);
	template<class T>
	void print_vector(const std::vector<T>& vec); 
private:	
	std::mt19937 m_generator;	
};

PatternMatch::PatternMatch(const std::string& text,
                           const std::string& pattern) :
m_text(text),
m_pattern(pattern)  
{
	std::fill(m_partial_match_table.begin(), 
		m_partial_match_table.end(), 0);  
}

const std::string& PatternMatch::get_text() const
{
	return m_text;
}

const std::string& PatternMatch::get_pattern() const
{
	return m_pattern;
}

bool PatternMatch::pattern_unique_match() const
{
    const std::size_t text_length = m_text.length();
	const std::size_t pattern_length = m_pattern.length();

	if (text_length == 0)
	{
	  	return pattern_length == 0;
	}

	if (pattern_length == 0)
	{
    	return false;
	}

	if (text_length < pattern_length)
	{
    	return false;
	}

	const std::size_t text_iter_count = text_length - pattern_length + 1;
	for (std::size_t i = 0; i < text_iter_count;)
	{
    	for (std::size_t j = 0; j < pattern_length; ++j)
		{
        	const char& t = m_text[i + j];
        	const char& p = m_pattern[j];

			if (t == p)
			{
            	if (j == (pattern_length - 1))
				{
                	return true;
				}
			}
			else
			{
			  	i += (j == 0 ? 1 : j);
            	break;
			}
		}
	}

	return false;
}

TestHelperClass::TestHelperClass(const PatternMatch& p)
: m_p(p)
{
}

void TestHelperClass::pattern_unique_match() const
{
    const bool test_match = m_p.get_text().find(m_p.get_pattern()) != 
	  						std::string::npos;
    const bool result = m_p.pattern_unique_match();

    if (test_match == result)
	{
	  	if (test_match)
		{
	  		std::cout << "Match " << m_p.get_text() << 
		    	         " " << m_p.get_pattern() << "\n";
		}
		else
		{
	  		std::cout << "No Match " << m_p.get_text() << 
		    	         " " << m_p.get_pattern() << "\n";
		}
    	return;
	}
    
	const std::string msg = "Un-Expected result ";
	const std::string expected = std::to_string(test_match);
	const std::string result_str = std::to_string(result);
    throw std::logic_error(msg + expected + " " + result_str);
}

void HelperClass::test_uniqueness(const std::string& str) const
{
    std::unordered_set<char> values;
    for (const auto& c : str)
    {
        if (values.count(c) == 0)
		{
        	values.insert(c);
			continue;
		}

		const std::string error = "Charcaters are not unqiue " + str;
        throw std::invalid_argument(error);
    }
}

HelperClass::HelperClass()
{
	std::random_device rd;
	std::mt19937 m_generator(rd());
}

std::string HelperClass::get_random_string(const std::size_t len,
	                                       bool unique_characters)
{
    if (len == 0)
	{
    	return std::string();
	}

	const std::string alphabets = "abcdefghijklmnopqrstwxyz";
    const std::size_t alphabet_length = alphabets.length();

    if (alphabets.length() != alphabet_length)
	{
    	std::abort();
	}

	std::random_device rd;
	std::mt19937 generator(rd());
    std::uniform_int_distribution<> dis(1, alphabet_length);

	std::string str;

	if (unique_characters)
	{
       str = alphabets;
	}
	else
	{
		for (std::size_t i = 0; i < len; ++i)
	  	{
			str.push_back(alphabets[dis(generator)]);
	  	} 
	}

	std::shuffle(str.begin(), str.end(), generator);

	if (unique_characters)
	{
    	str = str.substr(0, len);
	}

	return str;
}

std::size_t HelperClass::get_random_integer()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<> distribution(1, 
		50);
		//std::numeric_limits<int>::max());  
	return distribution(generator);
}

template<class T>
void 
HelperClass::print_vector(const std::vector<T>& vec) 
{
	std::string str;  
	for (std::size_t i = 0; i < vec.size(); ++i)  
	{
    	str += std::to_string(vec[i]);
		if (i != (vec.size() -1))
		{
        	str += ' ';
		}
	}

	std::cout << str << "\n";
}

std::size_t 
HelperClass::get_random_integer_less_than(const std::size_t val)
{    
	std::random_device rd;
	std::mt19937 generator(rd());
  
	std::uniform_int_distribution<> distribution(1, val);
	return distribution(generator); 
}

void exercise_32_1_2()
{
    try
    {
	  	{
		  	for (std::size_t i = 0; i < 10; ++i)
			{
            	HelperClass h; 
			   	const std::size_t text_length = 
				 	h.get_random_integer();
			   	const std::size_t pattern_length = 
					h.get_random_integer_less_than(text_length);
             	class TestHelperClass t(
					PatternMatch(h.get_random_string(text_length, false), 
						h.get_random_string(pattern_length, true)
					)
				); 
        		t.pattern_unique_match();                              
			}

		}
		{
        	class TestHelperClass t(PatternMatch("acaabdabc", "abc")); 
        	t.pattern_unique_match();
		} 
		{
        	class TestHelperClass t(PatternMatch("acaabdab", "bc")); 
        	t.pattern_unique_match();
		} 

		{
        	class TestHelperClass t(PatternMatch("wrqxrnpeqregnkjgdzhwshyblcjcsirqjqekjzmmcyt", "qreg")); 
        	t.pattern_unique_match();
        	
		}
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << "Invalid argument " << ex.what() << "\n";
    }
    catch (const std::logic_error& ex)
    {
        std::cout << "Logical error " << ex.what() << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "Exception " << ex.what() << "\n";
    }
}


//###################################################################################

// The Rabin-Karp Algorithm

// p [1...m], T [1..n]
// ts : Decimal value of length m substring T [s+1 ... s + m]
// Certainly ts = p if and pnly if T [s + 1 ... s + m] = P[m]
// 
// Example: 31415 = 3 * 10000 + 1 * 1000 + 4 * 100 + 1 * 10 + 5 


//###################################################################################

//###################################################################################

// String matching with finite automata
//

void PatternMatch::compute_partial_match_table()
{
  	uint64_t prefix_scanner = 0;
	for (std::size_t i = 1; i < m_pattern.length(); ++i)
	{
    	const char& s = m_pattern[i];
		const char& p = m_pattern[prefix_scanner];

		if (s == p)
		{
		  	m_partial_match_table[i] = prefix_scanner;
        	++prefix_scanner;
		}
		else
		{
        	while (1)	 
			{
              	if (prefix_scanner == 0)  
				{
                	break;
				}
				const char& p2 = m_pattern[prefix_scanner];
				if (s == p2)
				{
                	continue;
				}

            	const size_t previous_position = prefix_scanner - 1; 
				prefix_scanner = m_partial_match_table[previous_position];
			}
		}
	}
}

bool PatternMatch::kmp()
{
	compute_partial_match_table();	
	return true;
}

const std::vector<size_t>& get_partial_match_table() const
{
	return m_partial_match_table;
}

void TestHelperClass::kmp()
{
}

void TestHelperClass::test_compute_partial_match_failed() const
{


}

void test_compute_partial_match_failed()
{
	
}

//###################################################################################

int main()
{
    test_compute_partial_match_failed();
    return 0;
}
