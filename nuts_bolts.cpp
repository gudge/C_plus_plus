#include <iostream>
#include <set>
#include <vector>
#include <utility>

using vec_char = std::vector<char>;
using pair_vec_char = std::pair<vec_char, vec_char>; 

void match_nots_bolts();
bool check_all_nuts_and_bolts_present(const vec_char& nuts,
                                      const vec_char& bolts);
pair_vec_char match(vec_char& nuts,
                    vec_char& bolts);

void check_match(const vec_char& nuts,
                 const vec_char& bolts);

bool check_all_nuts_and_bolts_present(const vec_char& nuts,
                                      const vec_char& bolts)
{
    std::set<char> check; 
    for (const auto& n : nuts)
    {
        check.insert(n);
    }
   
    for (const auto& b : bolts)    
    {
        if (check.find(b) == check.end())
        {
            return false;
        }
        check.erase(b);
    }

    return true;
}

void check_match(const vec_char& nuts,
                 const vec_char& bolts)
{
    bool match = nuts.size() == bolts.size();
    
    if (match)
    {
        for (std::size_t i = 0; i < nuts.size(); ++i)
        {
            if (nuts[i] != bolts[i])    
            {
                match = false;
                break;
            }
        }
    }

    if (match)
    {
        std::cout << "Match" << std::endl;
    }
    else
    {
        std::cout << "Not a match" << std::endl;
    }
}

pair_vec_char match(vec_char& nuts,
                    vec_char& bolts)
{
        
}

void
match_nots_bolts()
{
    vec_char nuts = {'@', '$', '%', '^', '*'};
    vec_char bolts = {'%', '@', '^', '*', '$'};
    if (!check_all_nuts_and_bolts_present(nuts, bolts))
    {
        return;
    }
    match(nuts, bolts);
    check_match(nuts, bolts);
}

int
main()
{
    match_nots_bolts();
    return 0;
}
