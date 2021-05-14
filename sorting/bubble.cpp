// Classic bubble sort algorithm
#include <iostream>
#include <new>

void bubble_sort(int n, int arr[]);

void print(int n, int arr[])
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "enter number of elements" << std::endl;
    int n = 0;
    std::cin >> n;

    int *arr = new (std::nothrow) int[n];
    if (nullptr == arr)
    {
        std::cout << "cannot allocate memory" << std::endl;
        return -1;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "input array: \t";
    print(n, arr);
    bubble_sort(n, arr);
    std::cout << "sorted array: \t";
    print(n, arr);
}

void bubble_sort(int n, int arr[])
{
    // do not raverse to last element because
    // we are doing j+1 in the loop.
    n = n - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1]) // swap
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}