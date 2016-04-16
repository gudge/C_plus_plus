// https://www.hackerrank.com/challenges/deque-stl

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#define DEBUG 1

std::shared_ptr<std::istream> get_input(const std::string& fname,
                                        const bool ifstdin = false);
std::vector<uint32_t> read_values(std::shared_ptr<std::istream> input);
void dequeue_stl(const std::string& fname);
bool input_validation(int argc);
template <class T>
void print_output(const std::vector<T>& output);

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

std::vector<std::uint32_t>
read_values(std::shared_ptr<std::istream> input)
{
    std::string line;
    if (!std::getline(*input, line))
    {
        return std::move(std::vector<std::uint32_t>());
    }
    const std::string delimiter(" ");
    std::vector<std::string> sline;
    std::size_t next = -1;
    std::size_t current;
    do
    {
        current = next + 1;    
        next = line.find_first_of(delimiter, current);
        sline.push_back(line.substr(current, next - current));
    }
    while (next != std::string::npos); 
    std::vector<std::uint32_t> val;
    val.reserve(sline.size());
    for (const auto& s : sline)
    {
        std::stringstream sT(s);
        std::uint32_t x; 
        sT >> x;
        val.push_back(x);
    }
#if DEBUG2
    for (const auto& v : val)
    {
        std::cout << v << " ";
    }

    std::cout << std::endl;
#endif
    return std::move(val);
}

template <class T>
void
print_output(const std::vector<T>& output)
{
    if (output.empty())
    {
        std::cout << std::endl;
        return;
    }
    for (std::uint64_t i = 0; i < output.size() - 1; ++i)
    {
        std::cout << output[i] << " ";
    }
    std::cout << output[output.size() - 1] << std::endl;
}

void
dequeue_stl(const std::string& fname)
{
    std::shared_ptr<std::istream> input = get_input(fname);
    const std::uint32_t T = read_values(input)[0];
#ifdef DEBUG
    std::cout << "T " << T << std::endl;
#endif
	for (std::uint32_t i = 0; i < T; ++i)
    {
        const std::vector<std::uint32_t> val = read_values(input);
        const std::uint32_t N = val[0];
        const std::uint32_t K = val[1];
#ifdef DEBUG
        std::cout << "N = " << N << " K = " << K << std::endl;
#endif
        const std::vector<std::uint32_t> A = read_values(input);
        print_output(A);
        std::vector<std::uint32_t> output;
        const std::uint32_t ITER = N - K + 1;
        output.reserve(ITER); 
        if (N == 1 || K == 1 || K >= N) 
        {
            print_output(A);
            return;
        }
        else
        {
            std::uint32_t max;
            std::uint32_t max2;
            if (a[0] < a[1])
            {
                max = a[1];
                max2 = a[0];
            }
            else
            {
                max = a[0];
                max2 = a[1];
            }
            if (N == 2)
            {
               output.push_back(max); 
               output.push_back(max2); 
               print_output(output);
               return
            }
            else
            {
                for (std::uint32_t j = 2; j < N; ++j)
                {
                    if (a[j] > max)
                    {
                        max2 = max;
                        max = a[j];
                    } 
                    else if (a[j] > max2)
                    {
                        max2 = a[j];
                    }
                    if (j == K)
                    {

                    }
                }
                
            //print_output(output);
            }
        }
    }
}

bool
input_validation(int argc)
{
    if (2 == argc)
    {
        return true;
    }
    else
    {
        std::cout << "Please provide filename" << std::endl;
        return false;
    }
}

int
main(int argc, char**argv)
{
    if (input_validation(argc))
    {
        dequeue_stl(std::string(argv[1]));
    }
    return 0;
}
