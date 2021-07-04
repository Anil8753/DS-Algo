

#include <iostream>
#include <vector>

using namespace std;

#include <set>

int solution(int X, vector<int> &A)
{
    const int target = (X * (X + 1)) / 2;
    int sum = 0;

    std::set<int> collection;

    for (size_t i = 0; i < A.size(); ++i)
    {
        int n = A[i];
        if (collection.find(n) == collection.end())
        {
            collection.insert(n);
            sum += n;

            if (target == sum)
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    std::vector<int> v = {1, 3, 1, 4, 2, 3, 5, 4};
    std::cout << solution(5, v) << std::endl;
    return 0;
}