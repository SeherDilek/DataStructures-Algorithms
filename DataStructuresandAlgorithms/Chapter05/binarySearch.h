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