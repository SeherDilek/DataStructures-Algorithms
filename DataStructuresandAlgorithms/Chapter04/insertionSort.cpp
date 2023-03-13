#include <iostream>

using namespace std;

void InsertionSort(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        int refValue = arr[i];
        int j;
        for (j = i - 1; j >= 0; --j)
        {
            if(arr[j] > refValue)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = refValue;
    }
}

int main()
{
    cout << "Insertion Sort" << endl;
    // Initialize a new array
    int arr[] = {43, 21, 26, 38, 17, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
    cout << endl;
    // Sort the array with InsertionSort algorithm
    InsertionSort(arr, arrSize);
    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}