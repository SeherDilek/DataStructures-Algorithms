#include <iostream>

using namespace std;

void Merge(int arr[], int startIndex, int middleIndex, int endIndex)
{
    int elementCount = endIndex - startIndex + 1;
    int* tempArray = new int[elementCount];

    // First array [startIndex ... middleIndex]
    int leftIndex = startIndex;

    // Secon array [midleIndex + 1 ... endIndex]
    int rightIndex = middleIndex + 1;

    int mergedIndex = 0;

    // Merge the two sub arrays
    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
        // Store the element at the left index if it is
        // smaller than the one at the right index
        if (arr[leftIndex] <= arr[rightIndex])
        {
            tempArray[mergedIndex] = arr[leftIndex];
            leftIndex++;
        }
        else
        {
            tempArray[mergedIndex] = arr[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    // If there is any remaining element in left subarray
    // that is not stored in the merged array yet
    while (leftIndex <= middleIndex)
    {
        tempArray[mergedIndex] = arr[leftIndex];

        leftIndex++;
        mergedIndex++;
    }

    // If there is remaining element in the right subarray
    // that is not stored in the merged array yet
    while (rightIndex <= endIndex)
    {
        tempArray[mergedIndex] = arr[rightIndex];

        rightIndex++;
        mergedIndex++;
    }

    // Copy the elements
    for (int i = 0; i < elementCount; i++)
        arr[startIndex + i] = tempArray[i];

    delete[] tempArray;
    return;
}

void MergeSort(int arr[], int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int middleIndex = (startIndex + endIndex) / 2;

        // Sort left subarray
        MergeSort(arr, startIndex, middleIndex);

        MergeSort(arr, middleIndex + 1, endIndex);

        Merge(arr, startIndex, middleIndex, endIndex);
    }
    return;
}

int main()
{
    cout << "Merge Sort" << endl;
    // Initialize a new array
    int arr[] = {7, 1, 5, 9, 3, 6, 8, 2};
    int arrSize = sizeof(arr)/sizeof(*arr);

    // Display the initial array
    cout << "Initial array: ";
    for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
    cout << endl;

    // Sort the array with MergeSort algorithm
    MergeSort(arr, 0, arrSize - 1);

    // Display the sorted array
    cout << "Sorted array : ";
    for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}