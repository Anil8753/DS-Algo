#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// Given A = [1, 3, 6, 4, 1, 2], the function should return 5.
// Given A = [1, 2, 3], the function should return 4.
// Given A = [−1, −3], the function should return 1.
int solution(vector<int> &A)
{
    // int i = 1;
    // while (A.end() != std::find(A.begin(), A.end(), i))
    // {
    //     i++;
    // }

    std::set<int> table;

    for (const int &n : A)
    {
        table.insert(n);
    }

    int i = 1;
    while (table.find(i) != table.end())
    {
        i++;
    }

    return i;
}

int main()
{
    {
        std::vector<int> v = {1, 3, 6, 4, 1, 2};
        std::cout << solution(v) << std::endl;
    }
    {
        std::vector<int> v = {1, 2, 3};
        std::cout << solution(v) << std::endl;
    }
    {
        std::vector<int> v = {-1, -3};
        std::cout << solution(v) << std::endl;
    }
    return 0;
}