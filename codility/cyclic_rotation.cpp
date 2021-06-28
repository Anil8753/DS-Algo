#include <iostream>
#include <vector>

using namespace std;

/*
 1 2 3 4 5
 2
 5 1 2 3 4
 4 5 1 2 3
 */
vector<int> solution(vector<int> &A, int K)
{
    if (A.size() == 0 || K <= 0)
        return A;

    vector<int> out = A;
    const int steps = K % A.size();

    for (int i = 1; i <= steps; ++i)
    {
        int last = out[out.size() - 1];
        for (int j = out.size() - 2; j >= 0; j--)
        {
            out[j + 1] = out[j];
        }

        out[0] = last;
    }

    return out;
}

void print(const std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    std::cout << std::endl;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    print(v);
    print(solution(v, 1));
    std::cout << std::endl;
    print(v);
    print(solution(v, 3));
    std::cout << std::endl;
    print(v);
    print(solution(v, 6));
    return 0;
}