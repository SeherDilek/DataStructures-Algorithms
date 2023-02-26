#include <iostream>
#include "queue.h"

using namespace std;

void RadixSort(int arr[], int arrSize)
{
    Queue<int>* buckets = new Queue<int>[10];
    int greatestNumber = arr[0];

    for (int i = 0; i < arrSize; i++)
    {
        if (greatestNumber < arr[i])
            greatestNumber = arr[i];
    }

    // Iterate through digits using exponential (10^exp)
    // to find the digit
    for (int exp = 1; greatestNumber / exp > 0; exp *= 10)
    {
        for (int i = 0; i < arrSize; i++)
        {
            buckets[(arr[i]/exp)%10].Enqueue(arr[i]);   
        }

        // Reconstruct the arry starting from the smallest digit
        // buckets
        // Reset the array counter before reconstructing
        int arrCounter = 0;
        for (int i = 0; i < 10; i++)
        {
            while (!buckets[i].IsEmpty())
            {
                arr[arrCounter++] = buckets[i].Front();
                buckets[i].Dequeue();
            }
        }
    }

    return;
}

int main()
{
    cout << "Radix Sort" << endl;
    // Initialize a new array
    int arr[] = {429, 3309, 65, 7439, 12, 9954, 30, 4567, 8, 882};
    int arrSize = sizeof(arr)/sizeof(*arr);
    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
    cout << endl;
    // Sort the array with QuickSort algorithm
    RadixSort(arr, arrSize);
    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}