// Statble selection sort
/*
select minimum in a variable
shift all the elements to right till the min index
*/

#include <iostream>
#include <assert.h>

// input:   1,1,3,0
// output   0,1,1,3
void sort(int *arr, int size)
{
    for (uint i = 0; i < size - 1; ++i)
    {
        uint min = i;
        for (uint j = i + 1; j < size; ++j)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        int val = arr[min];
        // instead of swaping,
        // first shift the array element from i to min
        for (uint k = min; k > i; k--)
        {
            arr[k] = arr[k - 1];
        }

        arr[i] = val;
    }
}

bool equal(int *a, int *b, uint size)
{
    for (uint i = 0; i < size; ++i)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

int main()
{
    int input[] = {1, 1, 3, 0, 4};
    int expected[] = {0, 1, 1, 3, 4};

    uint size = sizeof(input) / sizeof(int);
    sort(input, size);
    assert(equal(input, expected, size));
    // we are checking the address values,
    // later element must have address value greater than the earler one
    assert(&input[1] < &input[2]);
    return 0;
}