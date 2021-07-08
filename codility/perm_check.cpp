#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> &A)
{
    std::set<int> collection;
    int min = 0;
    int max = 0;
    for (const int &n : A)
    {
        min = std::min(min, n);
        max = std::max(max, n);
        collection.insert(n);
    }

    if (A.size() != collection.size())
        return 0;

    for (int i = 1; i <= A.size(); i++)
    {
        if (collection.find(i) == collection.end())
            return 0;
    }

    return 1;
}

int main()
{

    {
        std::vector<int> v = {4, 1, 3, 2};
        std::cout << solution(v) << std::endl;
    }
    {
        std::vector<int> v = {4, 1, 3};
        std::cout << solution(v) << std::endl;
    }

    return 0;
}