#include <iostream>
#include <vector>
#include <set>

int solution(std::vector<int> &A)
{
    std::set<int> collection;
    for (const auto &n : A)
        collection.insert(n);

    return static_cast<int>(collection.size());
}

int main()
{
    std::vector<int> A;
    A.resize(6);

    A[0] = 2;
    A[1] = 1;
    A[2] = 1;
    A[3] = 2;
    A[4] = 3;
    A[5] = 1;

    std::cout << solution(A) << std::endl;

    return 0;
}