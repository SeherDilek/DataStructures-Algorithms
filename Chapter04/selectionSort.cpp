#include <iostream>

using namespace std;

void SelectionSort(int arr[], int arrSize)
{
    int minIndex;
    for (int i = 0; i < arrSize - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    cout << "Selection Sort" << endl;
    // Initialize a new array
    int arr[] = {43, 21, 56, 78, 97, 30};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Display the initial array
    cout << "Initial array: ";
    for (int i = 0; i < arrSize; ++i)
    cout << arr[i] << " ";
    cout << endl;
    // Sort the array with SelectionSort algorithm
    SelectionSort(arr, arrSize);
    // Display the sorted array
    cout << "Sorted array : ";
    for (int i = 0; i < arrSize; ++i)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}