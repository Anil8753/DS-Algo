/*
For example, given array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
the function should return 1, as explained above.

PrefixSum = 4, 6, 8, 13, 14, 19, 27
loop 1 -> 7
    1 - min = 4
    1 - min = 2
    2 - min = 4
    .
    .
    .
    7 - min = 8
*/

#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
    float result = 9999999;
    int index = 0;

    for (size_t i = 0; i < A.size(); i++)
    {
        float min = 9999999;
        float sum = A[i];
        for (size_t j = i + 1; j < A.size(); j++)
        {
            sum += A[j];
            float average = sum / (j - i + 1);
            min = std::min(average, min);
        }

        if (min < result)
        {
            result = min;
            index = i;
        }
    }

    return index;
}

int main()
{
    std::vector<int> v = {4, 2, 2, 5, 1, 5, 8};
    std::cout << solution(v) << std::endl;
}