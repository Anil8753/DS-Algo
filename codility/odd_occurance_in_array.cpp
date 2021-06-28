
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
    std::unordered_map<int, int> table;
    for (const auto &n : A)
    {
        table[n] = table[n] + 1;
    }

    for (const auto &pair : table)
    {
        const int count = pair.second;
        if (count % 2)
        {
            return pair.first;
        }
    }
    return 0;
}

int main()
{
    std::vector<int> v = {1,
                          1,
                          2,
                          2,
                          3};
    std::cout << solution(v);
    return 0;
}