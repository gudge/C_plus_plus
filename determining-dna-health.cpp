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
//

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>
#include <cstdint>

// Problem statement


//###################################################################################
//32.1-2
//Suppose that all characters in the pattern P are different. Show how to accelerate
//NAIVE-STRING-MATCHER to run in time O.n/ on an n-character text T .


void exercise_32_1_2();

class PatternMatch
{
public:
    explicit PatternMatch(const std::string& text,
                          const std::string& pattern);
    void test_match() const;
private:
    bool match() const;
    void test_uniqueness(const std::string& str) const;

    std::string m_text;
    std::string m_pattern;
};

PatternMatch::PatternMatch(const std::string& text,
                           const std::string& pattern) :
m_text(text),
m_pattern(pattern)  
{
    test_uniqueness(m_pattern);
}

bool PatternMatch::match() const
{
    for (size_t i = 0; i < m_text.length();)
    {
        bool found = true;
        for (size_t j = 0; j < m_pattern.length(); ++j)
        {
            if (i >= m_text.length())
            {
                return false;
            }

            if (m_text[i] != m_pattern[j])
            {
                i += j - 1;     
                found = false;
                break;
            }

            ++i;
        }

        if (found)
        {
            return true;
        }
    }

    return true;
}

void PatternMatch::test_match() const
{
    const bool testMatch = m_text.find(m_pattern) != std::string::npos;
    const bool result = match();

    if (testMatch != result)
    {
        throw std::logic_error(std::string("Un-Expected result ") + 
                               std::string("Expected ") + std::to_string(testMatch) + " "  +
                               std::string("Result ") + std::to_string(result));
    }
}

void PatternMatch::test_uniqueness(const std::string& str) const
{
    std::unordered_set<char> values;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (values.count(*it) != 0)
        {
            throw std::invalid_argument(std::string("Charcaters are not unqiue " + str));
        }
        values.insert(*it);
    }
}

void exercise_32_1_2()
{
    try
    {
        class PatternMatch p1("acaabc", "abc");
        p1.test_match();

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
        std::cout << ex.what() << "\n";
    }
}


//###################################################################################

int main()
{
    exercise_32_1_2();
    return 0;
}
