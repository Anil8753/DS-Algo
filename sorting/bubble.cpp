// Classic bubble sort algorithm
#include <iostream>
#include <new>
#include <functional>

class Container
{
public:
    Container(unsigned int _size)
    {
        size = _size;
        arr = new (std::nothrow) int[size];
    }

    ~Container()
    {
        delete[] arr;
    }

    int &operator[](int index)
    {
        return arr[index];
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void bubble_sort()
    {
        auto fnSwap = [](int *x, int *y)
        {
            int temp = *x;
            *x = *y;
            *y = temp;
        };

        // do not raverse to last element because
        // we are doing j+1 in the loop.
        const unsigned int n = size - 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (arr[j] > arr[j + 1]) // swap
                {
                    fnSwap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }

private:
    int *arr = nullptr;
    unsigned int size = 0;
};

int main()
{
    std::cout << "enter number of elements" << std::endl;
    int n = 0;
    std::cin >> n;

    Container c(n);

    for (int i = 0; i < n; ++i)
        std::cin >> c[i];

    std::cout << "input array: \t";
    c.print();
    c.bubble_sort();
    std::cout << "sorted array: \t";
    c.print();
}
