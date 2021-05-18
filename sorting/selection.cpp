#include <iostream>
#include <map>
#include <vector>
#include <assert.h>

// input     5 4 3 2 1 0
// output    0 1 2 3 4 5
void sort(int *arr, uint size)
{
    auto fnSwap = [](int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    };

    for (uint i = 0; i < size - 1; ++i)
    {
        uint min_index = i;

        for (uint j = i + 1; j < size; ++j)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }

        fnSwap(&arr[i], &arr[min_index]);
    }
}

bool equal(int *a, int *b, uint size)
{
    for (uint i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}

void print(int *arr, uint size)
{
    for (uint i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    {
        int arr[] = {5, 4, 3, 2, 1, 0};
        int expected[] = {0, 1, 2, 3, 4, 5};
        sort(arr, sizeof(arr) / sizeof(int));
        assert(equal(arr, expected, sizeof(arr) / sizeof(int)));
    }

    {
        int arr[] = {-55, 4, 3, 2, 1, 0};
        int expected[] = {-55, 0, 1, 2, 3, 4};
        sort(arr, sizeof(arr) / sizeof(int));
        assert(equal(arr, expected, 6));
    }

    {
        int arr[] = {-55, 4, 3, -200, 1, -100};
        int expected[] = {-200, -100, -55, 1, 3, 4};
        sort(arr, sizeof(arr) / sizeof(int));
        assert(equal(arr, expected, sizeof(arr) / sizeof(int)));
    }
}