#include <iostream>
#include <vector>
/*
4, 3, 1, 0 = v
0  1  2  3  4 = 1
1  1  0  1  1
1  2  2  3  4 = temp
*/
void count_sort(std::vector<int> &v)
{
    int max = 0;
    int min = 0;
    for (const auto &n : v)
    {
        max = std::max(max, n);
        min = std::min(min, n);
    }

    // normalize
    for (auto &n : v)
        n = n - min;

    std::vector<int> temp(max - min + 1, 0);
    for (size_t i = 0; i < v.size(); i++)
        temp[v[i]]++;

    for (size_t i = 1; i < temp.size(); i++)
        temp[i] = temp[i] + temp[i - 1];

    std::vector<int> out(v.size());

    for (int i = v.size() - 1; i >= 0; --i)
    {
        int ele = v.at(i);
        temp[ele] = temp[ele] - 1;
        out[temp[ele]] = ele;
    }

    v = out;

    // de-normalize
    for (auto &n : v)
        n = n + min;
}

int main()
{
    std::vector<int> v = {4, 5, 7, 8, -1, -9, 1, 3, 7, 7, 5};
    std::vector<int> expected = {-9, -1, 1, 3, 4, 5, 5, 7, 7, 7, 8};

    // std::vector<int> v = {7, 8, 1, 9};
    // std::vector<int> expected = {1, 1, 3, 4, 5, 5, 7, 7, 7, 8, 9};

    count_sort(v);

    for (const auto &n : v)
        std::cout << n << " ";
    std::cout << std::endl;

    assert(v == expected);
    return 0;
}