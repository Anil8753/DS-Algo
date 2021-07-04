#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    // assume there are N+1 element;
    // we will try to find the missing element
    // n*(n+1)/2

    // current sum with missing element. It is extra by 1
    int sum = 0;
    for (const auto &i : A)
    {
        sum += i;
    }

    // sum of N+1 should be
    int s = (A.size() + 1) * (A.size() + 2) / 2;
    int missing_element = s - sum;

    return missing_element;
}

int main()
{
    vector<int> v = {2, 3, 1, 5};
    std::cout << solution(v);
    return 0;
}