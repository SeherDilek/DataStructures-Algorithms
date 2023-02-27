#include <iostream>
#include "binarySearch.h"

using namespace std;

int ExponentialSearch(int arr[], int arrSize, int val)
{
    if (arrSize <= 0)
        return -1;

    int blockIndex = 1;

    while (blockIndex < arrSize && arr[blockIndex] < val)
    {
        blockIndex *= 2;
    }
    
    return BinarySearch(arr, blockIndex / 2, arrSize, val);
}

int main()
{
    cout << "Exponential Search" << endl;
    // Initialize a new array
    int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Define value to be searched
    int searchedValue = 48;
    // Find the searched value using blockIndex Search
    int i = ExponentialSearch(arr, arrSize, searchedValue);
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