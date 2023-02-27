#include <iostream>

using namespace std;

int TernarySearch(int arr[], int startIndex, int endIndex, int val)
{
    if (startIndex > endIndex)
        return -1;

    int midLeftIndex = startIndex + (endIndex - startIndex) / 3;
    if (arr[midLeftIndex] == val)
        return midLeftIndex;

    int midRightIndex = midLeftIndex + (endIndex - startIndex) / 3;
    if (arr[midRightIndex] == val)
        return midRightIndex;

    if (arr[midLeftIndex] > val)
        return TernarySearch(arr, startIndex, midLeftIndex - 1, val);
    else if (arr[midRightIndex] > val)
        return TernarySearch(arr, midLeftIndex - 1, midRightIndex + 1, val);
    else
        return TernarySearch(arr, midRightIndex + 1, endIndex, val);

    return -1;
}

int main()
{
    cout << "Ternary Search" << endl;
    // Initialize a new array
    int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47,
    48, 50};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Define value to be searched
    int searchedValue = 16;
    // Find the searched value using Ternary Search
    int i = TernarySearch(arr, 0, arrSize - 1, searchedValue);
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
