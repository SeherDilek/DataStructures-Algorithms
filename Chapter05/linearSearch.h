#include <iostream>

using namespace std;


int LinearSearch(int arr[], int startIndex, int endIndex, int val)
{
    for (int i = startIndex; i < endIndex; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}