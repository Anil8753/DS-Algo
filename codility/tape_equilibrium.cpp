#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
    int sum = 0;
    for (const auto n : A)
        sum += n;

    int left = 0;
    int right = sum;
    int min_diff = 999999;
    for (size_t i = 0; i < A.size() - 1; ++i)
    {
        left += A[i];
        right -= A[i];
        int diff = std::abs(left - right);
        min_diff = std::min(min_diff, diff);
    }

    return min_diff;
}

int main()
{
    std::vector<int> v = {3, 1, 2, 4, 3};
    // std::vector<int> v = {1, 1};
    std::cout << solution(v);
    return 0;
}