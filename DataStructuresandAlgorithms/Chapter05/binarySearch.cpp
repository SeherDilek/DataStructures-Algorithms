#include <iostream>

using namespace std;

// For sorted array 
int BinarySearch(int arr[], int startIndex, int endIndex, int val)
{
    if (startIndex > endIndex)
        return -1;

    auto midIndex = startIndex + (endIndex - startIndex) / 2;
    if (arr[midIndex] == val)
        return midIndex;
    else if (arr[midIndex] > val)
        return BinarySearch(arr, startIndex, midIndex, val);
    else
        return BinarySearch(arr, midIndex, endIndex, val);

    return - 1;
}

int main()
{
    cout << "Binary Search" << endl;
    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47,
    48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Define value to be searched
    int searchedValue = 16;
    // Find the searched value using Binary Search
    int i = BinarySearch(arr, 0, arrSize - 1, searchedValue);
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