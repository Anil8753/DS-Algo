/*
For example, given:

  A[0] = 0
  A[1] = 1
  A[2] = 0
  A[3] = 1
  A[4] = 1
We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).
the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer that can have one of the following values: 0, 1.
The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.
*/
#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
    std::vector<int> prexfix_sum;
    prexfix_sum.resize(A.size());

    prexfix_sum[0] = A.at(0);
    for (size_t i = 1; i < A.size(); ++i)
        prexfix_sum[i] = prexfix_sum[i - 1] + A.at(i);

    long long n = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
        {
            n += (prexfix_sum.at(A.size() - 1) - prexfix_sum.at(i));
        }
    }

    if (n > 1000000000)
        return -1;

    return n;
}

int main()
{
    std::vector<int> v = {0, 1, 0, 1, 1};
    std::cout << solution(v) << std::endl;
    return 0;
}