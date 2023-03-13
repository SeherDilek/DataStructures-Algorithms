#include <iostream>

using namespace std;

int Partition(int arr[], int startIndex, int endIndex)
{
    int pivot = arr[startIndex];

    int middleIndex = startIndex;

    for (int i = startIndex + 1; i <= endIndex; i++)
    {
        if (arr[i] < pivot)
        {
            ++middleIndex;
            swap(arr[i], arr[middleIndex]);
        }
    }

}