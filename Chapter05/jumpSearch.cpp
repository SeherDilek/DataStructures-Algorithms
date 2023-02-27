#include <iostream>
#include <math.h>
#include "linearSearch.h"

using namespace std;

int JumpSearch(int arr[], int arrSize, int val)
{
    if (arrSize <= 0)
        return -1;

    int step = sqrt(arrSize);

    int blockIndex = 0;

    // Find the starting index of the block contains the value
    while (blockIndex < arrSize && arr[blockIndex] < val)
        blockIndex += step;

    if (blockIndex == 0 && arr[blockIndex] == val)
        return blockIndex;

    return LinearSearch(arr, blockIndex - step, arrSize, val);
}

int main()
{
    cout << "Jump Search" << endl;
    // Initialize a new array
    int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Define value to be searched
    int searchedValue = 42;
    // Find the searched value using Jump Search
    int i = JumpSearch(arr, arrSize, searchedValue);
    // Notify user the result
    // if the return is not -1,
    // the searched value is found
    if(i != -1)
    {
        cout << searchedValue << " is found in index ";
        cout << i << endl;
    }
    else
    {
        cout << "Could not find value " << searchedValue;
        cout << endl;
    }
    return 0;
}
