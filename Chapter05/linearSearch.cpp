#include <iostream>
#include "linearSearch.h"

using namespace std;

int main()
{
    cout << "Linear Search" << endl;
    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30, 25, 18};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Define value to be searched
    int searchedValue = 30;
    // Find the searched value using Linear Search
    int i = LinearSearch(arr, 0, arrSize - 1, searchedValue);
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