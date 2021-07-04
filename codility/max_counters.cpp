#include <iostream>
#include <vector>

using namespace std;

#include <algorithm>

vector<int> solution(int N, vector<int> &A)
{
    std::vector<int> result;
    result.resize(N);

    int max_ele = 0;
    int i = 0;
    int e = 0;
    for (const auto &op : A)
    {
        if (1 <= op && op <= N)
        {
            i = op - 1;
            result[i] += 1;
            max_ele = std::max(max_ele, result[i]);
        }
        else if (op > N)
        {
            result.assign(result.size(), max_ele);
        }
    }

    return result;
}

int main()
{
    std::vector<int> v = {3, 4, 4, 6, 1, 4, 4};
    int n = 5;

    const auto out = solution(n, v);
    for (const auto &x : out)
        std::cout << x << std::endl;

    return 0;
}