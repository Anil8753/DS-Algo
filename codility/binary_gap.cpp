#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>

std::string to_binary_str(int N)
{
    int size = (sizeof(int) * 8) - 1;

    std::stringstream ss;

    while (size--)
    {
        int mask = 1 << size;
        ss << ((N & mask) ? 1 : 0);
    }
    return ss.str();
}

// finds the max binary gap
int solution(int N)
{
    std::string s = to_binary_str(N);

    int max_gap = 0;

    for (int i = 0; i < s.length();)
    {
        int gap = 0;
        size_t start = s.find_first_of('1', i);
        if (std::string::npos == start)
        {
            break;
        }

        size_t end = s.find_first_of('1', start + 1);

        if (std::string::npos == end)
        {
            break;
        }

        gap = end - start - 1;
        max_gap = std::max(gap, max_gap);
        i = end;
    }

    return max_gap;
}

int main()
{
    std::cout << to_binary_str(328) << "  " << solution(328) << std::endl;
    std::cout << to_binary_str(1610612737) << "  " << solution(1610612737) << std::endl;
    std::cout << to_binary_str(100) << "  " << solution(100) << std::endl;
    std::cout << to_binary_str(7) << "  " << solution(7) << std::endl;
    return 0;
}